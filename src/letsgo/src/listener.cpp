#include "ros/ros.h"
#include "std_msgs/String.h"

void tachDulieu(const std_msgs::String::ConstPtr& chuoi)
{
    const char *a;
    a = chuoi->data.c_str();
    // std::stringstream ss(a);
    char tam[20];
    char data1[20];
    char data2[20];
    int data_1;
    int data_2;
    int dem=0; 
    int i=2;
    strcpy(tam,a);
    for(;tam[i]!=',';i++)
    {
        data1[dem]=tam[i];
        dem++;
    }
    data1[dem]='\0';
    i=i+1;
    dem=0;
    for(;tam[i]!=',';i++)
    {
        data2[dem]=tam[i];
        dem++;
    }
    data2[dem]='\0';
    data_1 = std::stoi(data1);
    data_2 = std::stoi(data2);
    ROS_INFO("Chuoi 1 la: %d", data_1);
    ROS_INFO("Chuoi 2 la: %d", data_2);
    //ROS_INFO("Xuat: %s",tam);
    
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;

    ros::Subscriber topic_sub = nh.subscribe("chuoi", 1000, tachDulieu);
    ros::spin();

    return 0;

}