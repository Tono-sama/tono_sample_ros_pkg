#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/PoseStamped.h>

ros::Publisher turtle_ps_pub;
geometry_msgs::PoseStamped turtle_ps;

void init(){
	turtle_ps.header.frame_id = "turtle1";
	turtle_ps.pose.position.z = 0.0;
}

void turtle_pose_callback(const turtlesim::Pose::ConstPtr& pose){
	turtle_ps.header.stamp = ros::Time::now();
	// turtlesim/Pose から PoseStamped に変換
	turtle_ps.pose.position.x = pose->x;
	turtle_ps.pose.position.y = pose->y;
	turtle_ps.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, pose->theta);

	turtle_ps_pub.publish(turtle_ps);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "turtle_state_node");
	ros::NodeHandle n;

	init();

	turtle_ps_pub = n.advertise<geometry_msgs::PoseStamped>("turtle_ps", 10);
	ros::Subscriber sub = n.subscribe("/turtle1/pose", 10, turtle_pose_callback);

	ros::spin();

	return 0;
}