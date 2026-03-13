#!/usr/bin/env python3
import rospy
from std_msgs.msg import String


def main():
    rospy.init_node('my_publisher')
    pub = rospy.Publisher('my_topic', String, queue_size=10)
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        msg = String(data='Hello, world!')
        pub.publish(msg)
        rate.sleep()


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
