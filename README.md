# dash_ros_class_ws

实验内容：主题、服务、动作（C++/Python，自定义消息/服务/动作）。

## 构建
```bash
cd ~/workspace/ex3pcyy/pcyy_ros_class_ws
catkin_make
source devel/setup.bash
```

## 运行示例
- 主题：
  - `rosrun my_class_pkg ros_publisher_node`
  - `rosrun my_class_pkg ros_subscriber_node`
  - Python: `rosrun my_class_pkg ros_publisher_node.py`, `rosrun my_class_pkg ros_subscriber_node.py`
  - Launch：`roslaunch my_class_pkg bringup_topic.launch`
- 自定义消息：`rosrun my_class_pkg msg_publisher_node` / `rosrun my_class_pkg msg_subscriber_node`
- 服务：
  - `rosrun my_class_pkg ros_server_node`
  - `rosrun my_class_pkg ros_client_node`
  - Python: `rosrun my_class_pkg ros_server.py` / `rosrun my_class_pkg ros_client.py`
- 动作：
  - `rosrun my_class_pkg ros_action_server`
  - `rosrun my_class_pkg ros_action_client`
  - Python: `rosrun my_class_pkg ros_action_server.py` / `rosrun my_class_pkg ros_action_client.py`

## 依赖
`roscpp`, `rospy`, `std_msgs`, `message_generation`, `message_runtime`, `actionlib`, `actionlib_msgs`
# ros_ex3_pcyy_3-13
