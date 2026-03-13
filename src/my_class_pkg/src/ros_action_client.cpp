#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <my_class_pkg/MyActionAction.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_action_client");
    actionlib::SimpleActionClient<my_class_pkg::MyActionAction> client("my_action", true);
    client.waitForServer();
    ROS_INFO("Waiting for action server to start...");

    my_class_pkg::MyActionGoal goal;
    goal.object_name = "world";
    ROS_INFO("Sending goal...");
    client.sendGoal(goal);

    bool finished = client.waitForResult(ros::Duration(30.0));
    if (finished)
    {
        auto state = client.getState();
        ROS_INFO("Action finished: %s", state.toString().c_str());
    }
    else
    {
        ROS_INFO("Action did not finish before timeout.");
    }
    return 0;
}
