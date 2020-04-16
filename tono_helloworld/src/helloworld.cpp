#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "helloworld_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(10); // Hz

	while(ros::ok()){
		std_msgs::String msg;
		msg.data = "hello, world !";
		ROS_INFO("message: %s", msg.data.c_str());

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}