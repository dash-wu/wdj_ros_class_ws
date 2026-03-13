#!/usr/bin/env python3
import rospy
import actionlib
from my_class_pkg.msg import MyActionAction, MyActionGoal

def feedback_cb(feedback):
    rospy.loginfo('Progress: %s', feedback.progress)

if __name__ == '__main__':
    rospy.init_node('my_client')
    client = actionlib.SimpleActionClient('my_action', MyActionAction)
    client.wait_for_server()
    goal = MyActionGoal(object_name='world')
    rospy.loginfo('Sending goal...')
    client.send_goal(goal, feedback_cb=feedback_cb)
    client.wait_for_result()
    res = client.get_result()
    if res and res.success:
        rospy.loginfo('Action succeeded')
    else:
        rospy.loginfo('Action failed')
