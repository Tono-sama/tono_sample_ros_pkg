#include <ros/ros.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "ros_shutdown_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(10); // Hz

	double st = ros::Time::now().toSec();
	while (ros::ok()){
		if(st+10 > ros::Time::now().toSec()){}
			else break;
		ros::spinOnce();
		loop_rate.sleep();
	} 

	ROS_INFO("hello, world !");

	ros::shutdown();

	return 0;
}