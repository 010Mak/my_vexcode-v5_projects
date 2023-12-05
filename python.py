# Import the VEX library
import vex

# Region for setting up VEX components
brain = vex.Brain()
# Replace 'PORT_NUMBER' with the actual port number where your range finder is connected
range_finder = vex.RangeFinder(brain.three_wire_port.a)
# Replace 'LEFT_MOTOR_PORT' and 'RIGHT_MOTOR_PORT' with the actual motor ports
left_motor = vex.Motor(vex.Ports.PORT1, vex.GearSetting.RATIO_18_1, False)
right_motor = vex.Motor(vex.Ports.PORT2, vex.GearSetting.RATIO_18_1, True)
drivetrain = vex.Drivetrain(left_motor, right_motor, 319.19, 292.1, vex.DistanceUnits.MM)

# Main loop
while True:
    # Read distance in inches
    distance = range_finder.distance(vex.DistanceUnits.IN)

    # Calculate speed
    if distance > 50:  # Assuming 50 inches is the distance for full speed
        speed = 100
    elif distance > 1:  # Decrease speed as the robot gets closer to the object
        speed = 100 * (distance / 50)
    else:  # If the object is very close, stop
        speed = 0

    # Set the drivetrain speed
    drivetrain.set_velocity(speed, vex.VelocityUnits.PCT)
    drivetrain.drive(vex.DirectionType.FWD)

    # Sleep to prevent CPU overload
    vex.sleep(10)  # Sleep for 10 milliseconds