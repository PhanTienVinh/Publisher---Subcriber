#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;

    ros::Publisher topic_pub = nh.advertise<std_msgs::String>("chuoi",1000);
    ros::Rate loop_rate(1);

    while(ros::ok())
    {
        std_msgs::String chuoi;
        chuoi.data = "A,123,456,B";

        topic_pub.publish(chuoi);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}