import rospy
import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
from geometry_msgs.msg import Twist
from wpg.msg import dist_to_fuzzy
from std_msgs.msg import Float32

# Define the universe of discourse for input and output variables
distance = ctrl.Antecedent(np.arange(0, 6.5, 0.5), 'distance')
vel = ctrl.Antecedent(np.arange(0, 2, 0.1), 'vel')
acceleration = ctrl.Consequent(np.arange(-0.5, 0.1, 0.01), 'acceleration')

# Define fuzzy sets for 'distance' considering max distance of 6 meters
distance['VN'] = fuzz.trimf(distance.universe, [0, 0, 1])
distance['N'] = fuzz.trimf(distance.universe, [0.5, 1.5, 2.5])
distance['MED'] = fuzz.trimf(distance.universe, [1.5, 3, 4.5])
distance['F'] = fuzz.trimf(distance.universe, [3.5, 5, 6])
distance['VF'] = fuzz.trimf(distance.universe, [5, 6, 6])

# Definindo os conjuntos fuzzy para a variavel 'vel'
vel['very_slow'] = fuzz.trimf(vel.universe, [0, 0, 0.1])
vel['slow'] = fuzz.trimf(vel.universe, [0.1, 0.15, 0.2])
vel['medium'] = fuzz.trimf(vel.universe, [0.15, 0.25, 0.3])
vel['fast'] = fuzz.trimf(vel.universe, [0.3, 0.4, 0.5])
vel['very_fast'] = fuzz.trimf(vel.universe, [0.4, 0.5, 0.6])

# Define fuzzy sets for 'acceleration'
acceleration['high_slowdown'] = fuzz.trimf(acceleration.universe, [-0.5, -0.4, -0.3])
acceleration['slowdown'] = fuzz.trimf(acceleration.universe, [-0.4, -0.3, -0.2])
acceleration['low_slowdown'] = fuzz.trimf(acceleration.universe, [-0.2, -0.1, 0])
acceleration['zero'] = fuzz.trimf(acceleration.universe, [-0.05, 0, 0.05])
acceleration['accel'] = fuzz.trimf(acceleration.universe, [0, 0.05, 0.1])

# Regras fuzzy
rule1 = ctrl.Rule(distance['VN'] & vel['very_slow'], acceleration['zero'])
rule2 = ctrl.Rule(distance['VN'] & vel['slow'], acceleration['low_slowdown'])
rule3 = ctrl.Rule(distance['VN'] & vel['medium'], acceleration['slowdown'])
rule4 = ctrl.Rule(distance['VN'] & vel['fast'], acceleration['high_slowdown'])
rule5 = ctrl.Rule(distance['VN'] & vel['very_fast'], acceleration['high_slowdown'])

rule6 = ctrl.Rule(distance['N'] & vel['very_slow'], acceleration['low_slowdown'])
rule7 = ctrl.Rule(distance['N'] & vel['slow'], acceleration['slowdown'])
rule8 = ctrl.Rule(distance['N'] & vel['medium'], acceleration['high_slowdown'])
rule9 = ctrl.Rule(distance['N'] & vel['fast'], acceleration['high_slowdown'])
rule10 = ctrl.Rule(distance['N'] & vel['very_fast'], acceleration['high_slowdown'])

rule11 = ctrl.Rule(distance['MED'] & vel['very_slow'], acceleration['slowdown'])
rule12 = ctrl.Rule(distance['MED'] & vel['slow'], acceleration['high_slowdown'])
rule13 = ctrl.Rule(distance['MED'] & vel['medium'], acceleration['accel'])
rule14 = ctrl.Rule(distance['MED'] & vel['fast'], acceleration['accel'])
rule15 = ctrl.Rule(distance['MED'] & vel['very_fast'], acceleration['accel'])

rule16 = ctrl.Rule(distance['F'] & vel['very_slow'], acceleration['high_slowdown'])
rule17 = ctrl.Rule(distance['F'] & vel['slow'], acceleration['accel'])
rule18 = ctrl.Rule(distance['F'] & vel['medium'], acceleration['accel'])
rule19 = ctrl.Rule(distance['F'] & vel['fast'], acceleration['accel'])
rule20 = ctrl.Rule(distance['F'] & vel['very_fast'], acceleration['accel'])

rule21 = ctrl.Rule(distance['VF'] & vel['very_slow'], acceleration['accel'])
rule22 = ctrl.Rule(distance['VF'] & vel['slow'], acceleration['accel'])
rule23 = ctrl.Rule(distance['VF'] & vel['medium'], acceleration['accel'])
rule24 = ctrl.Rule(distance['VF'] & vel['fast'], acceleration['accel'])
rule25 = ctrl.Rule(distance['VF'] & vel['very_fast'], acceleration['accel'])

# Criando o sistema de controle
acceleration_ctrl = ctrl.ControlSystem([rule1, rule2, rule3, rule4, rule5,
                                        rule6, rule7, rule8, rule9, rule10,
                                        rule11, rule12, rule13, rule14, rule15,
                                        rule16, rule17, rule18, rule19, rule20,
                                        rule21, rule22, rule23, rule24, rule25])
acceleration_sim = ctrl.ControlSystemSimulation(acceleration_ctrl)

class VelocityModifier:
    def __init__(self):
        self.acceleration_factor = 0.0
        self.last_fuzzy_input_time = rospy.Time.now()  # Track last fuzzy input timestamp
        self.fuzzy_timeout = rospy.Duration(0.5)  # Timeout for fuzzy inputs (adjust as needed)
        self.cmd_vel_sub = rospy.Subscriber('cmd_vel', Twist, self.cmd_vel_callback)
        self.cmd_vel_safe_pub = rospy.Publisher('cmd_vel_safe', Twist, queue_size=10)
        self.fuzzy_sub = rospy.Subscriber("entrada_fuzzy", dist_to_fuzzy, self.class_distance_callback)
        self.valid_fuzzy_input = False  # Tracks if fuzzy input is valid

    def cmd_vel_callback(self, msg):
        # Create a new message for cmd_vel_safe
        modified_msg = Twist()

        # Check for fuzzy input timeout
        if rospy.Time.now() - self.last_fuzzy_input_time > self.fuzzy_timeout:
            # No recent fuzzy input, reset the acceleration factor
            self.valid_fuzzy_input = False
            self.acceleration_factor = 0.0

        if not self.valid_fuzzy_input:
            # No valid fuzzy input, directly pass cmd_vel to cmd_vel_safe
            modified_msg = msg
        else:
            # Apply the calculated acceleration factor only to linear.x and angular.z
            modified_msg.linear.x = msg.linear.x + self.acceleration_factor
            modified_msg.angular.z = msg.angular.z + self.acceleration_factor

            # Set other velocities to zero
            modified_msg.linear.y = 0.0
            modified_msg.linear.z = 0.0
            modified_msg.angular.x = 0.0
            modified_msg.angular.y = 0.0

        # Publish the modified message
        self.cmd_vel_safe_pub.publish(modified_msg)

    def class_distance_callback(self, msg):
        # Update the timestamp for the last valid fuzzy input
        self.last_fuzzy_input_time = rospy.Time.now()

        class_name = msg.class_name
        distances = msg.distance

        # Check if the message is valid
        if class_name is None or distances is None:
            rospy.loginfo("Invalid fuzzy input detected. Reflecting cmd_vel.")
            self.valid_fuzzy_input = False
            self.acceleration_factor = 0.0
            return

        self.valid_fuzzy_input = True

        # Set default multipliers
        acceleration_multiplier = 1.0
        deceleration_multiplier = 1.0

        # Adjust multipliers based on class_name
        if class_name == "toolbox":
            acceleration_multiplier = 1.5
            deceleration_multiplier = 0.5
        elif class_name == "robot":
            acceleration_multiplier = 1.3
            deceleration_multiplier = 0.7
        elif class_name == "cone":
            acceleration_multiplier = 1.0
            deceleration_multiplier = 0.7
        elif class_name == "person":
            acceleration_multiplier = 0.7
            deceleration_multiplier = 1.0

        # Dynamically adjust fuzzy sets for acceleration
        acceleration['high_slowdown'].mf = fuzz.trimf(
            acceleration.universe, [-0.5 * deceleration_multiplier, -0.4 * deceleration_multiplier, -0.3 * deceleration_multiplier]
        )
        acceleration['slowdown'].mf = fuzz.trimf(
            acceleration.universe, [-0.4 * deceleration_multiplier, -0.3 * deceleration_multiplier, -0.2 * deceleration_multiplier]
        )
        acceleration['low_slowdown'].mf = fuzz.trimf(
            acceleration.universe, [-0.2 * deceleration_multiplier, -0.1 * deceleration_multiplier, 0]
        )
        acceleration['zero'].mf = fuzz.trimf(acceleration.universe, [-0.05, 0, 0.05])
        acceleration['accel'].mf = fuzz.trimf(
            acceleration.universe, [0, 0.05 * acceleration_multiplier, 0.1 * acceleration_multiplier]
        )

        # Set inputs for the fuzzy control system
        acceleration_sim.input['distance'] = distances
        acceleration_sim.input['vel'] = 0.2  # Example velocity value

        # Compute the fuzzy output
        try:
            acceleration_sim.compute()
            self.acceleration_factor = acceleration_sim.output['acceleration']
            rospy.loginfo("Calculated acceleration: %s" % self.acceleration_factor)
        except Exception as e:
            rospy.logwarn("Fuzzy computation failed: %s" % e)
            self.valid_fuzzy_input = False
            self.acceleration_factor = 0.0

if __name__ == '__main__':
    rospy.init_node('velocity_modifier')
    modifier = VelocityModifier()
    rospy.spin()