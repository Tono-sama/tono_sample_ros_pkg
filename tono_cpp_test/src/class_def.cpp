#include "cpp_test_header.hpp"

inline void CPP_TEST_CLASS::_init(){
	_msg.data = "hello, world !";
}

CPP_TEST_CLASS::CPP_TEST_CLASS(ros::NodeHandle n){
	_init();
	_pub = n.advertise<std_msgs::String>("cpp_test_msg", 1);
}

void CPP_TEST_CLASS::_loop(const ros::TimerEvent&){
	_pub.publish(_msg);
	#ifdef TOMO_DEBUG
	ROS_INFO("[CPP_TEST_CLASS] _msg = %s", _msg.data.c_str());
	#endif
}