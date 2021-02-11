#include "include.hpp"

__global__ void cuda_helloworld(){
    printf("hello, world from CUDA !!! (thredIdx=%d)\n", threadIdx.x);
}

void call_cuda_helloworld(){
    cuda_helloworld<<<1,1>>>();
    cudaDeviceSynchronize();
}