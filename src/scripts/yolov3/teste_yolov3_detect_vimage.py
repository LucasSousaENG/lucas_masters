import cv2
import numpy as np
import os

# Carregar o modelo YOLOv3
net = cv2.dnn.readNet('/home/lucas/Downloads/Dataset_trainning/yolov3-tiny_default.weights', '/home/lucas/Downloads/Dataset_trainning/yolov3-tiny_default.cfg')

# Carregar as classes
classes = []
with open("/home/lucas/Downloads/Dataset_trainning/lucas_classes.txt", "r") as f:
    classes = f.read().splitlines()

# Configurações para exibição de texto
font = cv2.FONT_HERSHEY_PLAIN
colors = np.random.uniform(0, 255, size=(len(classes), 3))

# Função para detectar objetos em uma imagem e mostrar as detecções
def detect_and_show(image_path):
    image = cv2.imread(image_path)
    height, width, _ = image.shape

    blob = cv2.dnn.blobFromImage(image, 1.0 / 255.0, (416, 416), swapRB=True, crop=False)
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
            if confidence > 0.1:
                center_x = int(detection[0] * width)
                center_y = int(detection[1] * height)
                w = int(detection[2] * width)
                h = int(detection[3] * height)

                x = int(center_x - w / 2)
                y = int(center_y - h / 2)

                boxes.append([x, y, w, h])
                confidences.append(float(confidence))
                class_ids.append(class_id)

    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.2, 0.4)
    if len(indexes) > 0:
        for i in indexes.flatten():
            x, y, w, h = boxes[i]
            label = str(classes[class_ids[i]])
            confidence = str(round(confidences[i], 2))
            color = colors[class_ids[i]]
            cv2.rectangle(image, (x, y), (x + w, y + h), color, 2)
            cv2.putText(image, label + " " + confidence, (x, y + 20), font, 1, (255, 255, 255), 2)

    cv2.imshow('Image', image)
    cv2.waitKey(2000)
    cv2.destroyAllWindows()

# Pasta contendo as imagens
input_folder = "/home/lucas/Downloads/Dataset_trainning/lucas_objects"

# Loop sobre todas as imagens na pasta e detectar objetos
for filename in os.listdir(input_folder):
    if filename.endswith(".jpg") or filename.endswith(".png"):
        image_path = os.path.join(input_folder, filename)
        detect_and_show(image_path)
