# Utilizando o source para atualizar os caminhos
source ~/jackal_navigation/devel/setup.bash

gnome-terminal --tab -- rosservice call /move_base/clear_costmaps "{}"

# Publicar os goals da testrun
gnome-terminal --tab -- python /home/lucas/jackal_navigation/src/wpg/Scripts/publish_goals.py

#gnome-terminal --tab -- python /home/lucas/Downloads/yolo_multi_detect_depth_v0.95.py
sleep 1

# Roda o script de spawn da toolbox
#gnome-terminal --tab -- python /home/lucas/Downloads/spawn_obj.py
sleep 1

# Logica fuzzy
#gnome-terminal --tab -- python /home/lucas/Downloads/fuzzy_lcs.py

# Gravacao de topicos para testes (lembre-se de mudar sempre o nome apos rodar o script)
#gnome-terminal --tab -- rosbag record -O default1.bag /odom /cmd_vel /cmd_vel_safe /entrada_fuzzy

sleep 1






