#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def cb(msg):
    rospy.loginfo("I heard %s", msg.data)

def main():
    rospy.init_node('my_subscriber', anonymous=True)
    rospy.Subscriber('my_topic', String, cb)
    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
