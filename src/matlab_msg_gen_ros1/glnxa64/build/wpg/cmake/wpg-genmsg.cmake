# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "wpg: 7 messages, 0 services")

set(MSG_I_FLAGS "-Iwpg:/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg;-Istd_msgs:/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg;-Istd_msgs:/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(wpg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_vel_modif.msg" NAME_WE)
add_custom_target(_wpg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wpg" "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_vel_modif.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_lcs.msg" NAME_WE)
add_custom_target(_wpg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wpg" "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_lcs.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_lcs.msg" NAME_WE)
add_custom_target(_wpg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wpg" "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_lcs.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_vel_modif.msg" NAME_WE)
add_custom_target(_wpg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wpg" "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_vel_modif.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy.msg" NAME_WE)
add_custom_target(_wpg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wpg" "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzyfied.msg" NAME_WE)
add_custom_target(_wpg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wpg" "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzyfied.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/vehicle_smc_gains.msg" NAME_WE)
add_custom_target(_wpg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wpg" "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/vehicle_smc_gains.msg" "std_msgs/Header"
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_vel_modif.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
)
_generate_msg_cpp(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_lcs.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
)
_generate_msg_cpp(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_lcs.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
)
_generate_msg_cpp(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_vel_modif.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
)
_generate_msg_cpp(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
)
_generate_msg_cpp(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzyfied.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
)
_generate_msg_cpp(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/vehicle_smc_gains.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
)

### Generating Services

### Generating Module File
_generate_module_cpp(wpg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(wpg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(wpg_generate_messages wpg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_vel_modif.msg" NAME_WE)
add_dependencies(wpg_generate_messages_cpp _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_lcs.msg" NAME_WE)
add_dependencies(wpg_generate_messages_cpp _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_lcs.msg" NAME_WE)
add_dependencies(wpg_generate_messages_cpp _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_vel_modif.msg" NAME_WE)
add_dependencies(wpg_generate_messages_cpp _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy.msg" NAME_WE)
add_dependencies(wpg_generate_messages_cpp _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzyfied.msg" NAME_WE)
add_dependencies(wpg_generate_messages_cpp _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/vehicle_smc_gains.msg" NAME_WE)
add_dependencies(wpg_generate_messages_cpp _wpg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(wpg_gencpp)
add_dependencies(wpg_gencpp wpg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wpg_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_vel_modif.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
)
_generate_msg_py(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_lcs.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
)
_generate_msg_py(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_lcs.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
)
_generate_msg_py(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_vel_modif.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
)
_generate_msg_py(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
)
_generate_msg_py(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzyfied.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
)
_generate_msg_py(wpg
  "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/vehicle_smc_gains.msg"
  "${MSG_I_FLAGS}"
  "/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
)

### Generating Services

### Generating Module File
_generate_module_py(wpg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(wpg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(wpg_generate_messages wpg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_vel_modif.msg" NAME_WE)
add_dependencies(wpg_generate_messages_py _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzy_lcs.msg" NAME_WE)
add_dependencies(wpg_generate_messages_py _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_lcs.msg" NAME_WE)
add_dependencies(wpg_generate_messages_py _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy_vel_modif.msg" NAME_WE)
add_dependencies(wpg_generate_messages_py _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/fuzzy.msg" NAME_WE)
add_dependencies(wpg_generate_messages_py _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/defuzzyfied.msg" NAME_WE)
add_dependencies(wpg_generate_messages_py _wpg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg/vehicle_smc_gains.msg" NAME_WE)
add_dependencies(wpg_generate_messages_py _wpg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(wpg_genpy)
add_dependencies(wpg_genpy wpg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wpg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wpg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(wpg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(wpg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg)
  install(CODE "execute_process(COMMAND \"/home/lucas/.matlab/R2021b/ros1/glnxa64/venv/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wpg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(wpg_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(wpg_generate_messages_py std_msgs_generate_messages_py)
endif()
