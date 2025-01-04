import cv2
import numpy as np
import rospy
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

net = cv2.dnn.readNet('/home/lucas/Downloads/Dataset_trainning/yolov3_training_final.weights', '/home/lucas/Downloads/Dataset_trainning/yolov3_testing.cfg')

classes = []
with open("/home/lucas/Downloads/Dataset_trainning/classes.txt", "r") as f:
    classes = f.read().splitlines()

bridge = CvBridge()

font = cv2.FONT_HERSHEY_PLAIN
colors = np.random.uniform(0, 255, size=(100, 3))

def image_callback(msg):
    global net, classes, font, colors

    img = bridge.imgmsg_to_cv2(msg, "bgr8")
    height, width, _ = img.shape

    blob = cv2.resize(img, (416, 416)) # Redimensione a imagem para 416x416
    blob = cv2.dnn.blobFromImage(blob, 1.0 / 255.0, (416, 416), swapRB=True, crop=False)

    net.setInput(blob)
    output_layers_names = net.getUnconnectedOutLayersNames()
    layerOutputs = net.forward(output_layers_names)

    boxes = []
    confidences = []
    class_ids = []

    for output in layerOutputs:
        for detection in output:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]
            if confidence > 0.3:
                center_x = int(detection[0]*width)
                center_y = int(detection[1]*height)
                w = int(detection[2]*width)
                h = int(detection[3]*height)

                x = int(center_x - w/2)
                y = int(center_y - h/2)

                boxes.append([x, y, w, h])
                confidences.append((float(confidence)))
                class_ids.append(class_id)
            #print(class_id)
    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.2, 0.4)
    if len(indexes)>0:
        for i in indexes.flatten():
            x, y, w, h = boxes[i]
            label = str(classes[class_ids[i]])
            confidence = str(round(confidences[i],2))
            color = colors[i]
            cv2.rectangle(img, (x,y), (x+w, y+h), color, 2)####
            cv2.putText(img, label + " " + confidence, (x, y+20), font, 1, (255,255,255), 2)

    cv2.imshow('Image', img)
    cv2.waitKey(1)

def main():
    rospy.init_node('yolo_detector', anonymous=True)
    rospy.Subscriber("/camera3/color/image_raw", Image, image_callback)
    rospy.spin()

if __name__ == '__main__':
    main()

cv2.destroyAllWindows()
