#include <ros/ros.h>
#include <ros/package.h>

#include <string>

std::string wav_name = "sound1.wav";
std::string bagfile_path = ros::package::getPath("tono_callback");

void timer_callback(const ros::TimerEvent&){
	std::string command="aplay -q " + bagfile_path + "/data/" + wav_name;
	printf("%s\n",command.c_str());
	int tmp=system(command.c_str());
	if(tmp) printf("Sound Cycle","Not Found %s\n",wav_name.c_str());
}

int main(int argc, char **argv){
	ros::init(argc, argv, "timer_callback_node");
	ros::NodeHandle n;

	ros::Rate loop_rate(10); // Hz

	ros::Timer timer = n.createTimer(ros::Duration(2.0), &timer_callback);

	int i=0;
	while(ros::ok()){
		i++;
		if(i>=100){
			ros::Duration(2.0).sleep();
			ros::shutdown();
			break;
		}
		printf("count:%d\n",i);
		ros::spinOnce();
		loop_rate.sleep();
	}

	// ros::spin();

	return 0;
}