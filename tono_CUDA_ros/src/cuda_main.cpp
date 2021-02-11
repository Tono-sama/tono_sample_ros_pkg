#include "include.hpp"

int main(int argc, char **argv){
    ros::init(argc, argv, "cuda_main_node");
    ros::NodeHandle n;

    ros::Rate rate(1.0);

    while (n.ok()){
        call_cuda_helloworld();
        rate.sleep();
    }
    return 0;
}