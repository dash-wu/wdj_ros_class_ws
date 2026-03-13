#!/usr/bin/env python3
import rospy
import actionlib
from my_class_pkg.msg import MyActionAction, MyActionFeedback, MyActionResult

class MyActionServer(object):
    def __init__(self, name):
        self._as = actionlib.SimpleActionServer(name, MyActionAction, execute_cb=self.execute_cb, auto_start=False)
        self._as.start()
        self._feedback = MyActionFeedback()
        self._result = MyActionResult()

    def execute_cb(self, goal):
        r = rospy.Rate(1)
        success = True
        for i in range(1, 11):
            if self._as.is_preempt_requested():
                rospy.loginfo('%s: Preempted', rospy.get_name())
                self._as.set_preempted()
                success = False
                break
            self._feedback.progress = i * 10
            rospy.loginfo('progress = %s', self._feedback.progress)
            self._as.publish_feedback(self._feedback)
            r.sleep()
        if success:
            self._result.success = True
            self._as.set_succeeded(self._result)

if __name__ == '__main__':
    rospy.init_node('my_server')
    server = MyActionServer('my_action')
    rospy.spin()
