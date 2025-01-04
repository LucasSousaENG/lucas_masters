Install using .rosinstall file in src folder:
wstool init
wstool merge lucasmasters.rosinstall
wstool update


In workspace repository (remember to clone specifically kinetic-devel versions when possible as they're the most updated:

git clone https://github.com/LucasSousaENG/wpg

git clone https://github.com/LucasSousaENG/jackal

git clone https://github.com/LucasSousaENG/gazebo_ros_pkgs

git clone https://github.com/LucasSousaENG/youbot

git clone https://github.com/LucasSousaENG/jackal_simulator

Merge the fork files within the folders

catkin_make

I'm still organizing the repository for better installation process. Meawhile, use the forked repositories avaiable in my github
