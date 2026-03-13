#include "ros/ros.h"
#include "my_class_pkg/MyServiceMsg.h"

bool myServiceCallback(my_class_pkg::MyServiceMsg::Request &req,
                       my_class_pkg::MyServiceMsg::Response &res)
{
    res.output = req.input * 2;
    ROS_INFO("Request: input = %ld, output = %ld", (long)req.input, (long)res.output);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_service_node");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("my_service", myServiceCallback);
    ROS_INFO("Ready to receive service requests.");
    ros::spin();
    return 0;
}
