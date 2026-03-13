#!/usr/bin/env python3
import rospy
from my_class_pkg.srv import MyServiceMsg, MyServiceMsgResponse

def handle(req):
    rospy.loginfo("Service request: %d", req.input)
    return MyServiceMsgResponse(output=req.input * 2)

if __name__ == "__main__":
    rospy.init_node("my_service_server")
    srv = rospy.Service("my_service", MyServiceMsg, handle)
    rospy.loginfo("Ready to handle requests")
    rospy.spin()
