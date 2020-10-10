cmake_minimum_required(VERSION 3.0.2)
project(tono_loop)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(ros_shutdown_node src/ros_shutdown.cpp)
add_executable(ros_timer_node src/ros_timer.cpp)

target_link_libraries(ros_shutdown_node
  ${catkin_LIBRARIES}
)
target_link_libraries(ros_timer_node
  ${catkin_LIBRARIES}
)