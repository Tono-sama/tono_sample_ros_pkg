cmake_minimum_required(VERSION 3.0.2)
project(tono_callback)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  roslib
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(timer_callback_node src/timer_callback.cpp)

target_link_libraries(timer_callback_node
  ${catkin_LIBRARIES}
)