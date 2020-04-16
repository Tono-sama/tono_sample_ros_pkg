#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "simple_talker_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(10); // Hz

	ros::Publisher pub = n.advertise<std_msgs::String>("topic_name", 10);

	while(ros::ok()){
		std_msgs::String msg;
		msg.data = "hello, world !";
		ROS_INFO("publish: %s", msg.data.c_str());
		pub.publish(msg);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}