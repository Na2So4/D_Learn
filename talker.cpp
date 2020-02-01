#include "ros/ros.h"  //Main header files in ROS
#include "std_msgs/String.h" //The header files of String.msg
#include <sstream> // Header files in C++

//This program is used to realize simple sending messages over the ROS system.

int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker"); //Initialize ROS
	
	ros::NodeHandle n; //NodeHandle is the main access point to communications with the ROS.
	
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  /* 1.The advertise()function is how you tell ROS that you want to publish on a given topic name.
     
     2.Tell the master that we are going to publish a message of type STD - msgs/string on chatter(the name of a topic).In this way,the master will tell all nodes that have subscribed to the chatter topic that there will be data publishing.
     
     3.The second parameter to advertise() is the size of the message queue used for publishing messages.If messages are published more quickly than we can send them,the number here specifies how many messages to buffer up before throwing some away.

     4.advertise() returns a Publisher object which allows you to publish messages on that topic through a call to publish().  Once all copies of the returned Publisher object are destroyed, the topic will be automatically unadvertised. */

       ros::Rate loop_rate(10);/* The ROS:: rate object allows you to specify the frequency of the self loop. It tracks the passage of time since the last call to rate:: sleep() and sleeps until a frequency cycle.*/

       int count = 0; /* A count of how many messages we have sent. This is used to create a unique string for each message. */

       while (ros::ok())
{
	std_msgs::String msg;

	std::stringstream ss;
	ss << "hello world" << count;
	msg.data = ss.str();

	ROS_INFO("%s", msg.data.c_str()); /*Ros_info and other similar functions can be used to replace functions such as printf / cout.*/

	chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();/*This statement calls the ROS:: rate object to sleep for a period of time to make the publishing frequency 10Hz.*/

        ++count;

}

	return 0;


}
