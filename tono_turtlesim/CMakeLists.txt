cmake_minimum_required(VERSION 2.8.3)
project(tono_turtlesim)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf
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

add_executable(turtle_controller2_node src/turtle_controller2.cpp)
add_executable(turtle_state_node src/turtle_state.cpp)

target_link_libraries(turtle_controller2_node
  ${catkin_LIBRARIES}
)
target_link_libraries(turtle_state_node
  ${catkin_LIBRARIES}
)
