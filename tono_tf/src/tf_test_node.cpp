#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf2_msgs/TFMessage.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "tf_test_node");
	ros::NodeHandle n;
	ros::NodeHandle pn("~");
	ros::Rate loop_rate(1); // Hz

    double x=0., y=0., z=0., roll=0., pitch=0., yaw=0.;

    ros::Publisher tf_msg_pub = n.advertise<tf2_msgs::TFMessage>("tf", 1);
    ros::Publisher tf_static_msg_pub = n.advertise<tf2_msgs::TFMessage>("tf_static", 1);

    tf2_msgs::TFMessage tf_msg_1;
    tf2_msgs::TFMessage tf_msg_2;
    tf2_msgs::TFMessage tf_msg_3;
    tf2_msgs::TFMessage tf_msg_4;
    tf2_msgs::TFMessage tf_msg_5;
    tf2_msgs::TFMessage tf_msg_6;

    tf_msg_1.transforms.resize(3);
    // frame_1 -> frame_2
    tf_msg_1.transforms[0].header.frame_id = "frame_1_1";
    tf_msg_1.transforms[0].child_frame_id = "frame_1_2";
    tf_msg_1.transforms[0].transform.translation.x = 1.0;
    tf_msg_1.transforms[0].transform.translation.y = 0.0;
    tf_msg_1.transforms[0].transform.translation.z = 0.0;
    tf_msg_1.transforms[0].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_2 -> frame_3
    tf_msg_1.transforms[1].header.frame_id = "frame_1_2";
    tf_msg_1.transforms[1].child_frame_id = "frame_1_3";
    tf_msg_1.transforms[1].transform.translation.x = 1.0;
    tf_msg_1.transforms[1].transform.translation.y = 1.0;
    tf_msg_1.transforms[1].transform.translation.z = 0.0;
    tf_msg_1.transforms[1].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_3 -> frame_4
    tf_msg_1.transforms[2].header.frame_id = "frame_1_3";
    tf_msg_1.transforms[2].child_frame_id = "frame_1_4";
    tf_msg_1.transforms[2].transform.translation.x = 1.0;
    tf_msg_1.transforms[2].transform.translation.y = 1.0;
    tf_msg_1.transforms[2].transform.translation.z = 0.0;
    tf_msg_1.transforms[2].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);


    tf_msg_2.transforms.resize(3);
    // frame_1 -> frame_2
    tf_msg_2.transforms[0].header.frame_id = "frame_2_1";
    tf_msg_2.transforms[0].child_frame_id = "frame_2_2";
    tf_msg_2.transforms[0].transform.translation.x = 1.0;
    tf_msg_2.transforms[0].transform.translation.y = 0.0;
    tf_msg_2.transforms[0].transform.translation.z = 0.0;
    tf_msg_2.transforms[0].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_2 -> frame_3
    tf_msg_2.transforms[1].header.frame_id = "frame_2_2";
    tf_msg_2.transforms[1].child_frame_id = "frame_2_3";
    tf_msg_2.transforms[1].transform.translation.x = 1.0;
    tf_msg_2.transforms[1].transform.translation.y = 1.0;
    tf_msg_2.transforms[1].transform.translation.z = 0.0;
    tf_msg_2.transforms[1].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_3 -> frame_4
    tf_msg_2.transforms[2].header.frame_id = "frame_2_3";
    tf_msg_2.transforms[2].child_frame_id = "frame_2_4";
    tf_msg_2.transforms[2].transform.translation.x = 1.0;
    tf_msg_2.transforms[2].transform.translation.y = 1.0;
    tf_msg_2.transforms[2].transform.translation.z = 0.0;
    tf_msg_2.transforms[2].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);

    tf_msg_3.transforms.resize(1);
    // frame_1 -> frame_2
    tf_msg_3.transforms[0].header.frame_id = "frame_1_2";
    tf_msg_3.transforms[0].child_frame_id = "frame_2_2";
    tf_msg_3.transforms[0].transform.translation.x = 1.0;
    tf_msg_3.transforms[0].transform.translation.y = -1.0;
    tf_msg_3.transforms[0].transform.translation.z = 0.0;
    tf_msg_3.transforms[0].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);

    tf_msg_4.transforms.resize(1);
    // frame_1 -> frame_2
    tf_msg_4.transforms[0].header.frame_id = "frame_1_3";
    tf_msg_4.transforms[0].child_frame_id = "frame_2_3";
    tf_msg_4.transforms[0].transform.translation.x = 1.0;
    tf_msg_4.transforms[0].transform.translation.y = 1.0;
    tf_msg_4.transforms[0].transform.translation.z = 0.0;
    tf_msg_4.transforms[0].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);


    tf_msg_5.transforms.resize(7);
    // frame_1 -> frame_2
    tf_msg_5.transforms[0].header.frame_id = "frame_1_1";
    tf_msg_5.transforms[0].child_frame_id = "frame_1_2";
    tf_msg_5.transforms[0].transform.translation.x = 1.0;
    tf_msg_5.transforms[0].transform.translation.y = 0.0;
    tf_msg_5.transforms[0].transform.translation.z = 0.0;
    tf_msg_5.transforms[0].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_2 -> frame_3
    tf_msg_5.transforms[1].header.frame_id = "frame_1_2";
    tf_msg_5.transforms[1].child_frame_id = "frame_1_3";
    tf_msg_5.transforms[1].transform.translation.x = 1.0;
    tf_msg_5.transforms[1].transform.translation.y = 1.0;
    tf_msg_5.transforms[1].transform.translation.z = 0.0;
    tf_msg_5.transforms[1].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_3 -> frame_4
    tf_msg_5.transforms[2].header.frame_id = "frame_1_3";
    tf_msg_5.transforms[2].child_frame_id = "frame_1_4";
    tf_msg_5.transforms[2].transform.translation.x = 1.0;
    tf_msg_5.transforms[2].transform.translation.y = 1.0;
    tf_msg_5.transforms[2].transform.translation.z = 0.0;
    tf_msg_5.transforms[2].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_1 -> frame_2
    tf_msg_5.transforms[3].header.frame_id = "frame_2_1";
    tf_msg_5.transforms[3].child_frame_id = "frame_2_2";
    tf_msg_5.transforms[3].transform.translation.x = 1.0;
    tf_msg_5.transforms[3].transform.translation.y = 0.0;
    tf_msg_5.transforms[3].transform.translation.z = 0.0;
    tf_msg_5.transforms[3].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_2 -> frame_3
    tf_msg_5.transforms[4].header.frame_id = "frame_2_2";
    tf_msg_5.transforms[4].child_frame_id = "frame_2_3";
    tf_msg_5.transforms[4].transform.translation.x = 1.0;
    tf_msg_5.transforms[4].transform.translation.y = 1.0;
    tf_msg_5.transforms[4].transform.translation.z = 0.0;
    tf_msg_5.transforms[4].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_3 -> frame_4
    tf_msg_5.transforms[5].header.frame_id = "frame_2_3";
    tf_msg_5.transforms[5].child_frame_id = "frame_2_4";
    tf_msg_5.transforms[5].transform.translation.x = 1.0;
    tf_msg_5.transforms[5].transform.translation.y = 1.0;
    tf_msg_5.transforms[5].transform.translation.z = 0.0;
    tf_msg_5.transforms[5].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    tf_msg_3.transforms.resize(1);
    // frame_1_2 -> frame_2_2
    tf_msg_5.transforms[6].header.frame_id = "frame_1_1";
    tf_msg_5.transforms[6].child_frame_id = "frame_2_1";
    tf_msg_5.transforms[6].transform.translation.x = 1.0;
    tf_msg_5.transforms[6].transform.translation.y = -1.0;
    tf_msg_5.transforms[6].transform.translation.z = 0.0;
    tf_msg_5.transforms[6].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);

    tf_msg_6.transforms.resize(7);
    // frame_1 -> frame_2
    tf_msg_6.transforms[0].header.frame_id = "frame_1_1";
    tf_msg_6.transforms[0].child_frame_id = "frame_1_2";
    tf_msg_6.transforms[0].transform.translation.x = 1.0;
    tf_msg_6.transforms[0].transform.translation.y = 0.0;
    tf_msg_6.transforms[0].transform.translation.z = 0.0;
    tf_msg_6.transforms[0].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_2 -> frame_3
    tf_msg_6.transforms[1].header.frame_id = "frame_1_2";
    tf_msg_6.transforms[1].child_frame_id = "frame_1_3";
    tf_msg_6.transforms[1].transform.translation.x = 1.0;
    tf_msg_6.transforms[1].transform.translation.y = 1.0;
    tf_msg_6.transforms[1].transform.translation.z = 0.0;
    tf_msg_6.transforms[1].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_3 -> frame_4
    tf_msg_6.transforms[2].header.frame_id = "frame_1_3";
    tf_msg_6.transforms[2].child_frame_id = "frame_1_4";
    tf_msg_6.transforms[2].transform.translation.x = 1.0;
    tf_msg_6.transforms[2].transform.translation.y = 1.0;
    tf_msg_6.transforms[2].transform.translation.z = 0.0;
    tf_msg_6.transforms[2].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_1 -> frame_2
    tf_msg_6.transforms[3].header.frame_id = "frame_2_1";
    tf_msg_6.transforms[3].child_frame_id = "frame_2_2";
    tf_msg_6.transforms[3].transform.translation.x = 1.0;
    tf_msg_6.transforms[3].transform.translation.y = 0.0;
    tf_msg_6.transforms[3].transform.translation.z = 0.0;
    tf_msg_6.transforms[3].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_2 -> frame_3
    tf_msg_6.transforms[4].header.frame_id = "frame_2_2";
    tf_msg_6.transforms[4].child_frame_id = "frame_2_3";
    tf_msg_6.transforms[4].transform.translation.x = 1.0;
    tf_msg_6.transforms[4].transform.translation.y = 1.0;
    tf_msg_6.transforms[4].transform.translation.z = 0.0;
    tf_msg_6.transforms[4].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    // frame_3 -> frame_4
    tf_msg_6.transforms[5].header.frame_id = "frame_2_3";
    tf_msg_6.transforms[5].child_frame_id = "frame_2_4";
    tf_msg_6.transforms[5].transform.translation.x = 1.0;
    tf_msg_6.transforms[5].transform.translation.y = 1.0;
    tf_msg_6.transforms[5].transform.translation.z = 0.0;
    tf_msg_6.transforms[5].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);
    tf_msg_3.transforms.resize(1);
    // frame_1_2 -> frame_2_2
    tf_msg_6.transforms[6].header.frame_id = "frame_1_3";
    tf_msg_6.transforms[6].child_frame_id = "frame_2_3";
    tf_msg_6.transforms[6].transform.translation.x = 1.0;
    tf_msg_6.transforms[6].transform.translation.y = -1.0;
    tf_msg_6.transforms[6].transform.translation.z = 0.0;
    tf_msg_6.transforms[6].transform.rotation = tf::createQuaternionMsgFromRollPitchYaw(0.0, 0.0, 0.0);



	while(ros::ok()){
        tf_msg_1.transforms[0].header.stamp = ros::Time::now();
        tf_msg_1.transforms[1].header.stamp = ros::Time::now();
        tf_msg_1.transforms[2].header.stamp = ros::Time::now();
        tf_msg_2.transforms[0].header.stamp = ros::Time::now();
        tf_msg_2.transforms[1].header.stamp = ros::Time::now();
        tf_msg_2.transforms[2].header.stamp = ros::Time::now();
        tf_msg_3.transforms[0].header.stamp = ros::Time::now();
        tf_msg_4.transforms[0].header.stamp = ros::Time::now();
        for(int i=0; i<7; i++){
            tf_msg_5.transforms[i].header.stamp = ros::Time::now();
            tf_msg_6.transforms[i].header.stamp = ros::Time::now();
        }

        // tf_static_msg_pub.publish(tf_msg_1);
        // tf_static_msg_pub.publish(tf_msg_2);
        // tf_msg_pub.publish(tf_msg_3);

        // tf_static_msg_pub.publish(tf_msg_5);
        tf_static_msg_pub.publish(tf_msg_6);

        // static int count=0;
        // count++;
        // if(count%2==0){
        //     // tf_msg_pub.publish(tf_msg_3);
        //     tf_static_msg_pub.publish(tf_msg_1);
        //     tf_static_msg_pub.publish(tf_msg_2);
        //     tf_static_msg_pub.publish(tf_msg_3);
        // }else{
        //     // tf_msg_pub.publish(tf_msg_4);
        //     tf_static_msg_pub.publish(tf_msg_1);
        //     tf_static_msg_pub.publish(tf_msg_2);
        //     tf_static_msg_pub.publish(tf_msg_4);
        // }

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}