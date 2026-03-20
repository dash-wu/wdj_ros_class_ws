#include <ros/ros.h>

// 包含必要的头文件，其中 TutorialsConfig.h 就是配置文件在编译过程中生成的头文件。
#include <dynamic_reconfigure/server.h>
#include <my_class_pkg/TutorialsConfig.h>

#include <boost/bind.hpp>
#include <boost/bind/placeholders.hpp>

void callback(my_class_pkg::TutorialsConfig &config, uint32_t level)
{
  (void)level;
  ROS_INFO("Reconfigure Request: %d %f %s %s %d",
           config.int_param,
           config.double_param,
           config.str_param.c_str(),
           config.bool_param ? "True" : "False",
           config.size);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "dynamic_tutorials");

  dynamic_reconfigure::Server<my_class_pkg::TutorialsConfig> server;
  dynamic_reconfigure::Server<my_class_pkg::TutorialsConfig>::CallbackType f;

  f = boost::bind(&callback, boost::placeholders::_1, boost::placeholders::_2);
  server.setCallback(f);

  ROS_INFO("Spinning node");
  ros::spin();
  return 0;
}
