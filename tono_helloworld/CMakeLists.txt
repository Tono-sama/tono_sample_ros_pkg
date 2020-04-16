cmake_minimum_required(VERSION 2.8.3)
project(tono_helloworld)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tono_helloworld
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(helloworld_node src/helloworld.cpp)

target_link_libraries(helloworld_node
  ${catkin_LIBRARIES}
)
