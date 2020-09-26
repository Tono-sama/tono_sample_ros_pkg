#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf2_msgs/TFMessage.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "tf_publisher_node");
	ros::NodeHandle n;
	ros::NodeHandle pn("~");
	ros::Rate loop_rate(10); // Hz

    double x=0., y=0., z=0., roll=0., pitch=0., yaw=0.;
    std::string base_frame = "base_frame";
    std::string child_frame = "child_frame";
    std::string tf_topic_name = "tf";

    pn.getParam("x", x);
	pn.getParam("y", y);
	pn.getParam("z", z);
    pn.getParam("roll", roll);
	pn.getParam("pitch", pitch);
	pn.getParam("yaw", yaw);
	pn.getParam("base_frame", base_frame);
	pn.getParam("child_frame", child_frame);
	pn.getParam("tf_topic_name", tf_topic_name);

    ros::Publisher tf_msg_pub = n.advertise<tf2_msgs::TFMessage>(tf_topic_name, 1);

    tf2_msgs::TFMessage tf_msg;
    tf_msg.transforms.resize(1);
    tf_msg.transforms[0].header.frame_id = base_frame;
    tf_msg.transforms[0].child_frame_id = child_frame;

	while(ros::ok()){
        tf_msg.transforms[0].header.stamp = ros::Time::now();
        tf_msg.transforms[0].transform.translation.x = x;
        tf_msg.transforms[0].transform.translation.y = y;
        tf_msg.transforms[0].transform.translation.z = z;
        tf_msg.transforms[0].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(roll, pitch, yaw);
        tf_msg_pub.publish(tf_msg);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}