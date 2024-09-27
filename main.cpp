#include "Intersection.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    Intersection intersection;

    // Simulate for 100 iterations
    for (int i = 0; i < 100; i++) {
        // Randomly add vehicles to the intersection
        if (rand() % 3 == 0) { // 1 in 3 chance to add a vehicle
            int dir = rand() % 4;
            switch (dir) {
            case 0:
                intersection.addVehicle("North");
                break;
            case 1:
                intersection.addVehicle("South");
                break;
            case 2:
                intersection.addVehicle("East");
                break;
            case 3:
                intersection.addVehicle("West");
                break;
            }
        }

        // Update the intersection state
        intersection.update();

        // Print the current status
        intersection.printStatus();

        // Wait for 1 second before the next iteration
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "-------------------------------------" << std::endl;
    }

    return 0;
}
