cmake_minimum_required(VERSION 3.0.2)
project(my_class_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  actionlib
  actionlib_msgs
)

## Message, Service, Action definitions
add_message_files(
  DIRECTORY msg
  FILES MyMessage.msg
)

add_service_files(
  DIRECTORY srv
  FILES MyServiceMsg.srv
)

add_action_files(
  DIRECTORY action
  FILES MyAction.action
)

generate_messages(
  DEPENDENCIES
  std_msgs
  actionlib_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime actionlib actionlib_msgs roscpp rospy std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

## C++ executables
add_executable(ros_publisher_node src/ros_publisher.cpp)
target_link_libraries(ros_publisher_node ${catkin_LIBRARIES})
add_dependencies(ros_publisher_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ros_subscriber_node src/ros_subscriber.cpp)
target_link_libraries(ros_subscriber_node ${catkin_LIBRARIES})
add_dependencies(ros_subscriber_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(msg_publisher_node src/msg_publisher.cpp)
target_link_libraries(msg_publisher_node ${catkin_LIBRARIES})
add_dependencies(msg_publisher_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(msg_subscriber_node src/msg_subscriber.cpp)
target_link_libraries(msg_subscriber_node ${catkin_LIBRARIES})
add_dependencies(msg_subscriber_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ros_server_node src/ros_server.cpp)
target_link_libraries(ros_server_node ${catkin_LIBRARIES})
add_dependencies(ros_server_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ros_client_node src/ros_client.cpp)
target_link_libraries(ros_client_node ${catkin_LIBRARIES})
add_dependencies(ros_client_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ros_action_server src/ros_action_server.cpp)
target_link_libraries(ros_action_server ${catkin_LIBRARIES})
add_dependencies(ros_action_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(ros_action_client src/ros_action_client.cpp)
target_link_libraries(ros_action_client ${catkin_LIBRARIES})
add_dependencies(ros_action_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Install Python scripts
catkin_install_python(PROGRAMS
  scripts/ros_publisher_node.py
  scripts/ros_subscriber_node.py
  scripts/ros_server.py
  scripts/ros_client.py
  scripts/ros_action_server.py
  scripts/ros_action_client.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Install targets
install(TARGETS
  ros_publisher_node
  ros_subscriber_node
  msg_publisher_node
  msg_subscriber_node
  ros_server_node
  ros_client_node
  ros_action_server
  ros_action_client
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
