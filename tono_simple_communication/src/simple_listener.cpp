#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String& msg){
	ROS_INFO("subscribe: %s", msg.data.c_str());
}

int main(int argc, char **argv){
	ros::init(argc, argv, "simple_listener_node");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("topic_name", 10, callback);

	ros::spin();

	return 0;
}