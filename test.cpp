#include "vex.h"

using namespace vex;

// Ensure these match your actual robot configuration names
extern drivetrain Drivetrain;
extern sonar RangeFinderA;

int main() {
    // Variables
    double dist;
    double speed;
    const double minDist = 1;   // Minimum distance for the speed to reach 0%
    const double startDist = 50; // Starting distance for full speed (100%)

    while(true) {
        // Read distance from Range Finder A
        dist = RangeFinderA.distance(inches);

        // Calculate speed based on distance
        if (dist > startDist) {
            speed = 100; // Maintain full speed
        } else if (dist > minDist) {
            speed = 100 * ((dist - minDist) / (startDist - minDist));
        } else {
            speed = 0; // Stop if too close
        }

        // Set drivetrain speed
        Drivetrain.setDriveVelocity(speed, percent);

        // Short delay to prevent CPU overload
        this_thread::sleep_for(10);
    }
}