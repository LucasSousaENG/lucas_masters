# Utilizando o source para atualizar os caminhos
source ~/jackal_navigation/devel/setup.bash

# Abrindo o terminal 1 e executando o launch do mundo e spawn do robo
gnome-terminal --tab -- roslaunch jackal_gazebo lucas_world.launch config:=front_laser

# Aguardando 5 segundos para o ROS iniciar completamente
sleep 5

# Abrindo o terminal 2 e executando o launch da odometria e nos de navegacao da simulacao
gnome-terminal --tab -- roslaunch jackal_navigation odom_navigation_demo.launch


# Abrindo o terminal 3 e executando o Rviz para visualizacao da simulacao
gnome-terminal --tab -- rviz

# Logica fuzzy
#gnome-terminal --tab -- python /home/lucas/Downloads/fuzzy_lcs.py
sleep 20
gnome-terminal --tab -- python /home/lucas/Downloads/yolo_multi_detect_depth_v0.95.py
sleep 1
gnome-terminal --tab -- python /home/lucas/Downloads/spawn_obj.py
# Abrindo o terminal 3 e executando o script Python para movimentacao 
# gnome-terminal --tab -- python /home/lucas/jackal_navigation/src/wpg/Scripts/publish_goals.py



