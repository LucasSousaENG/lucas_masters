#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry
from gazebo_msgs.srv import SpawnModel
from geometry_msgs.msg import Pose

# Defina as coordenadas alvo
TARGET_X = -3.5  # Coordenada X onde o objeto sera spawnado
TARGET_Y = -2.1  # Coordenada Y onde o objeto sera spawnado
THRESHOLD = 2.0  # Margem de erro para a posicao

def spawn_model():

    # Caminho do arquivo SDF (coloque o caminho completo para o arquivo SDF)
    sdf_file_path = "/usr/share/gazebo-7/models/factory/models/toolbox_metal/model.sdf"

    # Le o conteudo do arquivo SDF
    with open(sdf_file_path, 'r') as sdf_file:
        sdf_content = sdf_file.read()

    # Define a posicao onde o objeto sera spawnado
    pose = Pose()
    pose.position.x = TARGET_X
    pose.position.y = TARGET_Y
    pose.position.z = 0.1  # Para o cubo nao comecar colado ao chao

    # Aguarda o servico de spawn estar disponivel
    rospy.wait_for_service('/gazebo/spawn_sdf_model')

    try:
        spawn_model_service = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)
        spawn_model_service("caixa", sdf_content, "", pose, "world")
        rospy.loginfo("Objeto spawnado com sucesso!")
    except rospy.ServiceException as e:
        rospy.logerr("Falha ao spawnar o modelo: {}".format(e))

def odom_callback(msg):
    """Callback para processar a odometria do robo."""
    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y

    # Verifica se o robo atingiu a posicao alvo
    if abs(x - TARGET_X) < THRESHOLD and abs(y - TARGET_Y) < THRESHOLD:
        rospy.loginfo("Robo atingiu a posicao alvo. Spawnando o objeto...")
        spawn_model()

def monitor_position():
    """Funcao principal para inicializar o no e monitorar a posicao."""
    rospy.init_node('monitor_position')
    
    # Subscribes to the odometry topic (adjust the topic name to match your robot)
    rospy.Subscriber("/odom", Odometry, odom_callback)

    rospy.spin()

if __name__ == "__main__":
    try:
        monitor_position()
    except rospy.ROSInterruptException:
        pass
