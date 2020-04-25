#include "cpp_test_header.hpp"

int main(int argc, char **argv){
	ros::init(argc, argv, "cpp_test_node");
	ros::NodeHandle n;

	CPP_TEST_CLASS obj(n);

	ros::Timer timer = n.createTimer(ros::Duration(1.0), &CPP_TEST_CLASS::_loop, &obj);

	ros::spin();

	return 0;
}