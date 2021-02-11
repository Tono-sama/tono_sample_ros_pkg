cmake_minimum_required(VERSION 3.0.2)
project(tono_CUDA_ros)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

find_package(CUDA 10.0 REQUIRED)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)

set(CUDA_MAIN_NODE_SRC
  src/cuda_main.cpp
  src/cuda_func.cu
)

###########
## Build ##
###########

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${catkin_INCLUDE_DIRS}
  ${CUDA_INCLUDE_DIRS}
)

cuda_add_executable(cuda_main_node
  ${CUDA_MAIN_NODE_SRC}
)

target_link_libraries(cuda_main_node
  ${catkin_LIBRARIES}
  ${CUDA_LIBRARIES}
)