#include "Intersection.h"
#include <iostream>

// Constructor implementation
Intersection::Intersection()
    : northSouthLight(10, 2, 10), eastWestLight(10, 2, 10), vehicleCounter(0) {}

// Updates the intersection: traffic lights and vehicle movements
void Intersection::update() {
    // Update traffic lights
    northSouthLight.update();
    eastWestLight.update();

    // Move vehicles based on the traffic light states
    if (northSouthLight.getState() == TrafficLight::GREEN) {
        if (!northQueue.empty()) {
            northQueue.front().advance();
            std::cout << "Vehicle " << northQueue.front().getId() << " from North has passed the intersection." << std::endl;
            northQueue.pop();
        }
        if (!southQueue.empty()) {
            southQueue.front().advance();
            std::cout << "Vehicle " << southQueue.front().getId() << " from South has passed the intersection." << std::endl;
            southQueue.pop();
        }
    }

    if (eastWestLight.getState() == TrafficLight::GREEN) {
        if (!eastQueue.empty()) {
            eastQueue.front().advance();
            std::cout << "Vehicle " << eastQueue.front().getId() << " from East has passed the intersection." << std::endl;
            eastQueue.pop();
        }
        if (!westQueue.empty()) {
            westQueue.front().advance();
            std::cout << "Vehicle " << westQueue.front().getId() << " from West has passed the intersection." << std::endl;
            westQueue.pop();
        }
    }
}

// Adds a new vehicle to the queue based on its direction
void Intersection::addVehicle(const std::string& direction) {
    vehicleCounter++;
    Vehicle vehicle(vehicleCounter, direction);
    if (direction == "North") {
        northQueue.push(vehicle);
    }
    else if (direction == "South") {
        southQueue.push(vehicle);
    }
    else if (direction == "East") {
        eastQueue.push(vehicle);
    }
    else if (direction == "West") {
        westQueue.push(vehicle);
    }
}

// Prints the current status of the intersection
void Intersection::printStatus() const {
    std::cout << "North-South Light: " << northSouthLight.getStateAsString() << std::endl;
    std::cout << "East-West Light: " << eastWestLight.getStateAsString() << std::endl;

    std::cout << "Vehicles waiting:" << std::endl;
    std::cout << "  North Queue: " << northQueue.size() << std::endl;
    std::cout << "  South Queue: " << southQueue.size() << std::endl;
    std::cout << "  East Queue: " << eastQueue.size() << std::endl;
    std::cout << "  West Queue: " << westQueue.size() << std::endl;
}
