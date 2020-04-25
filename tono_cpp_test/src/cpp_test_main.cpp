#include "cpp_test_header.hpp"

int main(int argc, char **argv){
	#ifdef TOMO_DEBUG
	ros::init(argc, argv, "cpp_test_debug_node");
	#else
	ros::init(argc, argv, "cpp_test_node");
	#endif

	ros::NodeHandle n;

	CPP_TEST_CLASS obj(n);

	#ifdef TOMO_DEBUG
	ROS_INFO("cpp_test_debug_node");
	#else
	ROS_INFO("cpp_test_node");
	#endif


	ros::Timer timer = n.createTimer(ros::Duration(1.0), &CPP_TEST_CLASS::_loop, &obj);

	ros::spin();

	return 0;
}