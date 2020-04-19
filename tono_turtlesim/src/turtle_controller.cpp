#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "turtle_controller2_node");
	ros::NodeHandle n;
	ros::Rate loop_rate(10); // Hz

	ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

	geometry_msgs::Twist cmd_vel_msg;
	cmd_vel_msg.linear.x = 1.0;
	cmd_vel_msg.angular.z = 0.5;

	while(ros::ok()){
		ROS_INFO("cmd_vel_msg publish: (x=%lf, omega=%lf)", cmd_vel_msg.linear.x, cmd_vel_msg.angular.z = 0.5);
		cmd_vel_pub.publish(cmd_vel_msg);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}