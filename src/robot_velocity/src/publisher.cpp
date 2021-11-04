#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include <stdlib.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher");

  ros::NodeHandle n;

  //ros::Publisher velocity_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher velocity_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    geometry_msgs::Twist msg;
    //std_msgs::String msg; 

    //std::stringstream ss;
    //ss << "hello world " << count;

  msg.linear.x  = double(rand())/double(RAND_MAX);
  msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

    velocity_pub.publish(msg);
  
    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}
