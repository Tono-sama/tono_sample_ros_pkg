#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "turtle_controller3_node");
	ros::NodeHandle n;
	ros::NodeHandle pn("~");
	ros::Rate loop_rate(10); // Hz

	ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

    double speed = 0.0;
    double omega = 0.0;
    pn.getParam("/cmd_vel/speed", speed);
    pn.getParam("/cmd_vel/omega", omega);

	geometry_msgs::Twist cmd_vel_msg;
	cmd_vel_msg.linear.x = speed;
	cmd_vel_msg.angular.z = omega;

	while(ros::ok()){
		ROS_INFO("cmd_vel_msg publish: (x=%lf, omega=%lf)", cmd_vel_msg.linear.x, cmd_vel_msg.angular.z);
		cmd_vel_pub.publish(cmd_vel_msg);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}