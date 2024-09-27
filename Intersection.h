#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "TrafficLight.h"
#include "Vehicle.h"
#include <queue>
#include <string>

// Class representing an intersection with traffic lights and vehicles
class Intersection {
private:
    TrafficLight northSouthLight;      // Traffic light for North-South direction
    TrafficLight eastWestLight;        // Traffic light for East-West direction
    std::queue<Vehicle> northQueue;    // Queue of vehicles waiting from the North
    std::queue<Vehicle> southQueue;    // Queue of vehicles waiting from the South
    std::queue<Vehicle> eastQueue;     // Queue of vehicles waiting from the East
    std::queue<Vehicle> westQueue;     // Queue of vehicles waiting from the West
    int vehicleCounter;                // Counter for assigning unique IDs to vehicles

public:
    // Constructor
    Intersection();

    // Updates the state of the intersection
    void update();

    // Adds a vehicle to the appropriate queue based on direction
    void addVehicle(const std::string& direction);

    // Prints the current status of the intersection
    void printStatus() const;
};

#endif // INTERSECTION_H
