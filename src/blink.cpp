#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include <iostream>
#include "wiringPi.h"

#define LED 1

void blink_callback (const std_msgs::Bool::ConstPtr& msg)
{
  if (msg -> data == 1)
  {
    digitalWrite (LED,HIGH);
    ROS_INFO("LED ON");
  }
  if (msg -> data == 0)
  {
    digitalWrite (LED,LOW);
    ROS_INFO("LED OFF");
  }
}

int main(int argc,char** argv)
{
  ros::init(argc ,argv ,"blink");
  ROS_INFO("Start RPI LED Blink node");
  wiringPiSetup();
  pinMode(LED,OUTPUT);

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("led_blink",10,blink_callback);
  //led_blink is topic name
  ros::spin();
}

