#include "vex.h"

using namespace vex;

// Assuming you have already configured your robot's drivetrain and range finder in the VEX Robot Configuration.
extern drivetrain myDrivetrain;
extern sonar RangeFinderA;

int main() {
    // Initialize VEX components
    vexcodeInit();

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
        }

        // Set drivetrain speed
        myDrivetrain.setVelocity(speed, percent);

        // Other drivetrain controls here (if necessary)

        // Short delay to prevent CPU overload
        this_thread::sleep_for(10);
    }
}