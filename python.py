import vex

# Initialize VEX components
brain = vex.Brain()

# Configure the range finder on ports A and B
range_finder = vex.RangeFinder(brain.three_wire_port.a, brain.three_wire_port.b)

# Configure the motors. Adjust the settings as needed for your robot.
left_motor_a = vex.Motor(vex.Ports.PORT1, vex.GearSetting.RATIO_18_1, False)
left_motor_b = vex.Motor(vex.Ports.PORT2, vex.GearSetting.RATIO_18_1, False)
right_motor_a = vex.Motor(vex.Ports.PORT3, vex.GearSetting.RATIO_18_1, True)
right_motor_b = vex.Motor(vex.Ports.PORT4, vex.GearSetting.RATIO_18_1, True)

# Create a drivetrain using the four motors
drivetrain = vex.Drivetrain(left_motor_a, right_motor_a, 319.19, 292.1, vex.DistanceUnits.MM)
drivetrain.add_motor(left_motor_b)
drivetrain.add_motor(right_motor_b)

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