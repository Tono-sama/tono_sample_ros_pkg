cmake_minimum_required(VERSION 3.0.2)
project(tono_tf)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf
  tf2
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

add_executable(tf_publisher_node src/tf_publisher_node.cpp)
add_executable(tf_test_node src/tf_test_node.cpp)

target_link_libraries(tf_publisher_node
  ${catkin_LIBRARIES}
)
target_link_libraries(tf_test_node
  ${catkin_LIBRARIES}
)