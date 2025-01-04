#!/usr/bin/env python
# A intencao dessa versao do script e melhorar a otimizacao
import rospy
import numpy as np
from sensor_msgs.msg import PointCloud2, Image, CameraInfo
from cv_bridge import CvBridge, CvBridgeError
import cv2
import sensor_msgs.point_cloud2 as pc2
from wpg.msg import dist_to_fuzzy
import pcl

# Add the ROI size parameter (modifiable before running the algorithm)
ROI_SIZE = 25  # Set this to the desired size (e.g., 20 pixels)

class YOLOv3ObjectDetector:
    def __init__(self):
        self.bridge = CvBridge()
        self.classes = None
        self.COLORS = np.random.uniform(0, 255, size=(80, 3))

        # Caminhos dos arquivos
        self.weights_path = '/home/lucas/Downloads/Dataset_trainning/masters_detection/yolov3_training_last.weights'
        self.config_path = '/home/lucas/Downloads/Dataset_trainning/masters_detection/yolov3_testing.cfg'
        self.classes_path = '/home/lucas/Downloads/Dataset_trainning/masters_detection/classes.txt'

        # Carregando classes
        self.load_classes()

        # Carregando modelo YOLOv3
        self.net = self.load_model()

        # Subscribe ao topico de imagem
        rospy.Subscriber("/camera2/color/image_raw", Image, self.image_callback)

    def load_model(self):
        net = cv2.dnn.readNet(self.weights_path, self.config_path)
        return net

    def load_classes(self):
        with open(self.classes_path, 'r') as f:
            self.classes = [line.strip() for line in f.readlines()]

    def detect_objects(self, frame):
        height, width = frame.shape[:2]

        # Reduzindo a resolucao da imagem para acelerar o processamento
        resized_frame = cv2.resize(frame, (320, 320))

        blob = cv2.dnn.blobFromImage(resized_frame, 0.00392, (320, 320), (0, 0, 0), True, crop=False)
        self.net.setInput(blob)
        outs = self.net.forward(self.net.getUnconnectedOutLayersNames())

        class_ids = []
        confidences = []
        boxes = []
        centroids = []

        for out in outs:
            for detection in out:
                scores = detection[5:]
                class_id = np.argmax(scores)
                confidence = scores[class_id]
                if confidence > 0.5:
                    center_x = int(detection[0] * width)
                    center_y = int(detection[1] * height)
                    w = int(detection[2] * width)
                    h = int(detection[3] * height)

                    x = int(center_x - w / 2)
                    y = int(center_y - h / 2)

                    boxes.append([x, y, w, h])
                    confidences.append(float(confidence))
                    class_ids.append(class_id)

                    # Calculating centroid coordinates
                    centroid_x = x + w // 2
                    centroid_y = y + h // 2
                    centroids.append((centroid_x, centroid_y))

        return class_ids, confidences, boxes, centroids

    def draw_boxes(self, frame, class_ids, confidences, boxes, centroids):
        detected_objects = []
        font = cv2.FONT_HERSHEY_PLAIN
        for i in range(len(boxes)):
            x, y, w, h = boxes[i]
            label = str(self.classes[class_ids[i]])
            color = self.COLORS[class_ids[i]]
            centroid_x, centroid_y = centroids[i]
            cv2.rectangle(frame, (x, y), (x + w, y + h), color, 2)
            cv2.putText(frame, label, (x, y + 30), font, 1, (255,255,255), 2)
            cv2.circle(frame, (centroid_x, centroid_y), 5, (255,255,255), -1)
            cv2.putText(frame, "({}, {})".format(centroid_x, centroid_y), (centroid_x, centroid_y), font, 1, color, 2)

            # Draw ROI around the centroid
            top_left = (centroid_x - ROI_SIZE // 2, centroid_y - ROI_SIZE // 2)
            bottom_right = (centroid_x + ROI_SIZE // 2, centroid_y + ROI_SIZE // 2)
            cv2.rectangle(frame, top_left, bottom_right, (255, 0, 0), 2)  # Blue rectangle for ROI

            detected_objects.append({'class': label, 'centroid': (centroid_x, centroid_y)})
        return frame, detected_objects

    def image_callback(self, msg):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError as e:
            rospy.logerr(e)
            return

        class_ids, confidences, boxes, centroids = self.detect_objects(frame)
        result_frame, detected_objects = self.draw_boxes(frame, class_ids, confidences, boxes, centroids)
        depth_handler.update_detected_objects(detected_objects)
        cv2.imshow("YOLOv3 Object Detection", result_frame)
        cv2.waitKey(1)

class DepthImageHandler:
    def __init__(self):
        self.bridge = CvBridge()
        self.fx = None  # Focal length in x
        self.fy = None  # Focal length in y
        self.cx = None  # Principal point in x
        self.cy = None  # Principal point in y
        self.image_width = None
        self.image_height = None
        self.detected_objects = []  # Lista de objetos detectados

        # Publisher para publicar distancias personalizadas
        self.pub_distances = rospy.Publisher('entrada_fuzzy', dist_to_fuzzy, queue_size=10)

        # Subscribe ao topico de informacoes da camera
        rospy.Subscriber('/camera2/color/camera_info', CameraInfo, self.camera_info_callback)
        
        # Subscribe ao topico de nuvem de pontos
        rospy.Subscriber('/camera2/depth/points', PointCloud2, self.point_cloud_callback)

    def camera_info_callback(self, msg):
        self.fx = msg.K[0]  # Focal length in x
        self.fy = msg.K[4]  # Focal length in y
        self.cx = msg.K[2]  # Principal point in x
        self.cy = msg.K[5]  # Principal point in y
        self.image_width = msg.width
        self.image_height = msg.height

    def point_cloud_callback(self, msg):
        if self.fx is None or self.fy is None or self.cx is None or self.cy is None:
            rospy.logwarn("Camera parameters not yet received.")
            return

        # Lendo pontos da mensagem de nuvem de pontos
        points = pc2.read_points(msg, field_names=('x', 'y', 'z'), skip_nans=True)
        points_list = list(points)

        # Reduzir a densidade da nuvem de pontos (downsampling)
        downsampled_points = downsample_pointcloud(points_list)

        # Loop through the detected objects
        for obj in self.detected_objects:
            centroid_x, centroid_y = obj['centroid']

            # Set an initial minimum distance to a high value
            min_distance = float('inf')

            # Iterar pelos pontos downsampled e procurar pontos dentro da ROI
            for point in downsampled_points:
                x, y, z = point

                # Calculando as coordenadas de pixel (u, v) a partir do ponto 3D
                u = int((x * self.fx / z) + self.cx)
                v = int((y * self.fy / z) + self.cy)

                # Verificar se o ponto esta dentro da ROI em torno do centroide
                if (centroid_x - ROI_SIZE // 2 <= u <= centroid_x + ROI_SIZE // 2 and
                        centroid_y - ROI_SIZE // 2 <= v <= centroid_y + ROI_SIZE // 2):
                    # Verificar se este ponto esta mais proximo que o minimo anterior
                    if z < min_distance:
                        min_distance = z

            if min_distance < float('inf'):
                rospy.loginfo("Class: {}, Min distance to camera: {:.3f} meters".format(obj['class'], min_distance))
                # Publicar a distancia minima para cada classe detectada
                distance_msg = dist_to_fuzzy()
                distance_msg.distance = min_distance
                distance_msg.class_name = obj['class']
                self.pub_distances.publish(distance_msg)

    def update_detected_objects(self, detected_objects):
        self.detected_objects = detected_objects

def downsample_pointcloud(points, leaf_size=0.05):
    # Converte lista de pontos em uma nuvem de pontos PCL
    pcl_cloud = pcl.PointCloud()
    pcl_cloud.from_list(points)

    # Aplicar o filtro de voxel para downsampling
    sor = pcl_cloud.make_voxel_grid_filter()
    sor.set_leaf_size(leaf_size, leaf_size, leaf_size)  # Tamanho dos voxels (ajuste conforme necessario)
    filtered_cloud = sor.filter()

    # Retorna a nuvem de pontos filtrada como uma lista
    return filtered_cloud.to_list()

def main():
    rospy.init_node('yolov3_object_detector', anonymous=True)

    yolo_detector = YOLOv3ObjectDetector()
    global depth_handler
    depth_handler = DepthImageHandler()

    rospy.loginfo("Iniciado o no YOLOv3 Object Detector.")
    rospy.spin()

if __name__ == '__main__':
    main()
