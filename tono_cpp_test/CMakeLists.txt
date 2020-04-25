cmake_minimum_required(VERSION 2.8.3)
project(tono_cpp_test)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(cpp_test_node src/cpp_test_main.cpp src/class_def.cpp)

target_link_libraries(cpp_test_node
  ${catkin_LIBRARIES}
)
