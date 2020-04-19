cmake_minimum_required(VERSION 2.8.3)
project(tono_simple_communication)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tono_simple_communication
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_talker_node src/simple_talker.cpp)
add_executable(simple_listener_node src/simple_listener.cpp)
add_executable(turtle_controller_node src/turtle_controller.cpp)

target_link_libraries(simple_talker_node
  ${catkin_LIBRARIES}
)
target_link_libraries(simple_listener_node
  ${catkin_LIBRARIES}
)
target_link_libraries(turtle_controller_node
  ${catkin_LIBRARIES}
)
