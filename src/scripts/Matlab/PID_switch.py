import rospy
import time
from dynamic_reconfigure.msg import Config
from dynamic_reconfigure.client import Client

def callback(msg):
    parameters = msg.doubles  # ou msg.ints, msg.bools, msg.strs, etc. dependendo dos tipos de parametros
    for parameter in parameters:
        rospy.loginfo("Nome do Parametro: {}, Valor: {}".format(parameter.name, parameter.value))

def modify_pid_gains():
    # Inicialize o nó ROS
    rospy.init_node('modify_pid_gains_node')

    # Crie um cliente de reconfiguração dinâmica
    client = Client('/arm_1/arm_controller/gains/arm_joint_2')

    # Obtenha a configuração atual dos parâmetros
    config = client.get_configuration()

    # Modifique os ganhos individualmente
    config['p'] = 2000.0       #2000.0
    config['i'] = 0.01       #0.01
    config['d'] = 0.1      #0.1

    # Atualize os parâmetros através do serviço de reconfiguração dinâmica
    client.update_configuration(config)

    # Exiba os novos ganhos modificados
    rospy.loginfo("Novos ganhos do PID: P = {}, I = {}, D = {}".format(config['p'], config['i'], config['d']))

if __name__ == '__main__':

    while True:
        #rospy.init_node('print_values_node')

        rospy.Subscriber('/arm_1/arm_controller/gains/arm_joint_2/parameter_updates', Config, callback)

        print("\n Atualizacao")

        modify_pid_gains()

        time.sleep(2)

        #rospy.spin()   #Mantem o no em execucao aguardando eventos
