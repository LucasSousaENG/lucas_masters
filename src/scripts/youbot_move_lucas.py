#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32
import sys, select, termios, tty, signal

msg = """
Reading from the keyboard  and Publishing to Twist!
---------------------------
Moving around:
        w     
   a    s    d       

q/z : Aumentar velocidade linear em 10%
e/c : Aumentar velocidade linear em 10%

CTRL-C to quit
"""

moveBindings = {
    # x, y, theta ratio
    'w': (1, 0, 0),  # forwards
    's': (-1, 0, 0),  # backward
    'd': (0, 0, -1),  # turn right on spot
    'a': (0, 0, 1),  # turn left on spot
}

speedBindings = {
    'q': (1.1, 1.1),
    'z': (.9, .9),
    'e': (1, 1.1),
    'c': (1, .9),
}

class TimeoutException(Exception):
    pass

def getKey():
    def timeout_handler(signum, frame):
        raise TimeoutException()
    
    old_handler = signal.signal(signal.SIGALRM, timeout_handler)
    signal.alarm(1)  # this is the watchdog timing
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    try:
        key = sys.stdin.read(1)
    except TimeoutException:
        return "-"
    finally:
        signal.signal(signal.SIGALRM, old_handler)
    
    signal.alarm(0)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

speed = 0.1     # Estabelecendo valores iniciais de velocidade e curva
turn = 0.1
acceleration_factor = 0.0  # Initial acceleration factor

def vels(speed, turn):
    return "currently:\tspeed %s\tturn %s " % (speed, turn)

def acceleration_factor_callback(msg):
    global acceleration_factor
    acceleration_factor = msg.data

if __name__ == "__main__":
    settings = termios.tcgetattr(sys.stdin)
    
    pub = rospy.Publisher('cmd_vel_safe', Twist, queue_size=10)
    rospy.init_node('teleop_twist_keyboard')

    rospy.Subscriber('acceleration_factor', Float32, acceleration_factor_callback)

    x = 0
    y = 0
    th = 0
    status = 0

    try:
        print(msg)
        print(vels(speed, turn))
        while True:
            key = getKey()
            if key in moveBindings.keys():
                x = moveBindings[key][0]
                y = moveBindings[key][1]
                th = moveBindings[key][2]
            elif key in speedBindings.keys():
                speed = speed * speedBindings[key][0]
                turn = turn * speedBindings[key][1]

                print(vels(speed, turn))
                if status == 14:
                    print(msg)
                status = (status + 1) % 15
            else:
                x = 0
                y = 0
                th = 0
                acceleration_factor = 0
                if key == '\x03':
                    break

            twist = Twist()
            twist.linear.x = x * speed + acceleration_factor
            twist.linear.y = y * speed
            twist.linear.z = 0

            twist.angular.x = 0
            twist.angular.y = 0
            twist.angular.z = th * turn
            pub.publish(twist)


    except Exception as e:
        print(e)

    finally:
        twist = Twist()
        twist.linear.x = 0
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = 0
        pub.publish(twist)

        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
