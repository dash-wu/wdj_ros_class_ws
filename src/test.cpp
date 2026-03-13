#include <ros/ros.h>
#include <std_msgs/String.h>

// 主函数参数：补全缺失的空格
int main(int argc, char** argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "my_publisher");
    // 创建节点句柄：补全缺失的空格
    ros::NodeHandle nh;
    // 定义发布者对象：补全缺失的空格
    // 参数：话题名my_topic，消息队列长度10
    ros::Publisher pub = nh.advertise<std_msgs::String>("my_topic", 10);
    // 设置发布频率：1Hz（每隔1秒发布一次）
    ros::Rate rate(1.0);

    // ROS节点主循环
    while (ros::ok())
    {
        // 创建消息对象并赋值
        std_msgs::String msg;
        msg.data = "Hello,world!";
        
        // 发布消息
        pub.publish(msg);
        
        // 【ROS最佳实践】处理回调函数（无回调时也建议添加，保证节点正常运行）
        ros::spinOnce();
        
        // 按照设定频率休眠
        rate.sleep();
    }

    return 0;
}