#include "vex.h"

using namespace vex;

// Adjust these names to match your robot configuration
extern drivetrain Drivetrain;
extern sonar RangeFinder;  // Assuming this is the name of your range finder

int main() {
    // Variables
    double dist;
    double speed;
    const double minDist = 25.4;  // Minimum distance (1 inch) in millimeters
    const double startDist = 1270; // Starting distance (50 inches) in millimeters

    while(true) {
        // Read distance from Range Finder in millimeters
        dist = RangeFinder.distance(mm);

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
        Drivetrain.drive(forward);

        // Short delay to prevent CPU overload
        this_thread::sleep_for(10);
    }
}