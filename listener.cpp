#include "ros/ros.h"
#include "std_msgs/String.h"

//This program is used to realize simple receipt of messages over the ROS system.

void chatterCallback(const std_msgs::String::ConstPtr& msg) //Callback Functions 

{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");

	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	ros::spin();/*ROS:: spin() enters the self loop and can call the message callback function as soon as possible.*/

	
	return 0;
}

