# wdj_ros_class_ws

实验内容：主题、服务、动作（C++/Python，自定义消息/服务/动作）。

## 工作空间与构建

包源码在仓库内 `src/my_class_pkg`，建议链入 catkin 工作空间后编译（已配置则跳过 `ln`）：

```bash
ln -sf ~/dash-class-3/src/my_class_pkg ~/dash-class-3/ros_class_ws/src/my_class_pkg
cd ~/dash-class-3/ros_class_ws
catkin_make
```

**新终端直接使用 `rosrun`**：本机已在 `~/.bashrc` 中叠加 `~/dash-class-3/ros_class_ws/devel/setup.bash`。打开新终端或执行 `source ~/.bashrc` 后即可：

```bash
rospack find my_class_pkg   # 应能打印包路径
```

运行任何节点前需有 **roscore**（另开终端执行 `roscore`，或已用 `roslaunch` 带起 master）。

## 运行示例
- **参数**（私有/全局 `getParam` / `setParam`）：`rosrun my_class_pkg ros_param`（先 `roscore`）。可选在 launch 或命令行设置：`_my_param:=custom`（私有）或 `/my_param:=custom`（全局，视节点命名空间而定）。
- **动态参数（本包 `.cfg`）**：`rosrun my_class_pkg dynamic_reconfigure_node`，用 `rosrun rqt_reconfigure rqt_reconfigure` 打开界面，选 `dynamic_tutorials` 调节 `int_param`、`double_param` 等。
- **动态参数 + 速度发布（依赖 `upros_message` 的 `.cfg`）**：先起仿真或 turtlesim（`/turtle1/cmd_vel`），再 `rosrun my_class_pkg ros_dynamic_speed_node`，在 rqt_reconfigure 中选对应节点调节 `double_param` 作为线速度。
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
`roscpp`, `rospy`, `std_msgs`, `message_generation`, `message_runtime`, `actionlib`, `actionlib_msgs`, `dynamic_reconfigure`；动态参数示例另需包 `upros_message`（与本仓库 `src/upros_message` 一同加入工作空间后 `catkin_make`）。
