#include "vex.h"

using namespace vex;

// Ensure these match your actual robot configuration names
extern drivetrain Drivetrain;
extern sonar RangeFinderA;

int main() {
    // Variables
    double dist;
    double speed;
    const double maxSpeed = 100; // Max speed of the drivetrain
    const double maxDist = 50;   // Max distance for full speed in inches

    while(true) {
        // Read distance from Range Finder A
        dist = RangeFinderA.distance(inches);

        // Calculate speed based on distance
        speed = maxSpeed * (dist / maxDist);

        // Limit the speed to maxSpeed
        if(speed > maxSpeed) {
            speed = maxSpeed;
        } else if (speed < 0) {
            speed = 0; // Ensure speed doesn't go negative
        }

        // Set drivetrain speed - adjust this part based on your robot configuration
        Drivetrain.setDriveVelocity(speed, percent);

        // Other drivetrain controls here (if necessary)

        // Short delay to prevent CPU overload
        this_thread::sleep_for(10);
    }
}