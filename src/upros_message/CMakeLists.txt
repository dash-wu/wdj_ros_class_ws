cmake_minimum_required(VERSION 3.0.2)
project(upros_message)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  message_generation
  roscpp
)

generate_dynamic_reconfigure_options(
  cfg/Tutorials.cfg
)

catkin_package(
  CATKIN_DEPENDS dynamic_reconfigure message_runtime
)

