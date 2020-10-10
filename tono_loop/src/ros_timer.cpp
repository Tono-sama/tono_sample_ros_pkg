#include <ros/ros.h>

int count = 0;

void timer_callback(const ros::TimerEvent&){
  std::cout << "timer_callback(" << count << ")" << std::endl;
	count++;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "ros_timer_node");
	ros::NodeHandle n;

	ros::Timer timer = n.createTimer(ros::Duration(1.0), &timer_callback);
	ros::spin();

	return 0;
}