#ifndef CPP_TEST_HEADER
#define CPP_TEST_HEADER

#include <ros/ros.h>
#include <std_msgs/String.h>

class CPP_TEST_CLASS{
private:
	ros::Publisher _pub;
	std_msgs::String _msg;
	void _init();
		
public:
	CPP_TEST_CLASS(ros::NodeHandle n);
	void _loop(const ros::TimerEvent&);
	
};

#endif