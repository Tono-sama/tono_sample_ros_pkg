cmake_minimum_required(VERSION 2.8.3)
project(tono_cpp_test)

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

add_executable(cpp_test_node src/cpp_test_main.cpp src/class_def.cpp)
add_executable(cpp_test_debug_node src/cpp_test_main.cpp src/class_def.cpp)

target_compile_definitions(cpp_test_debug_node PRIVATE TOMO_DEBUG)

target_link_libraries(cpp_test_node
  ${catkin_LIBRARIES}
)
target_link_libraries(cpp_test_debug_node
  ${catkin_LIBRARIES}
)