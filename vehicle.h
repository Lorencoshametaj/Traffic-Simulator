#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

// Class representing a vehicle
class Vehicle {
private:
    int id;                // Unique identifier for the vehicle
    std::string direction; // Direction the vehicle is heading (e.g., "North", "South", "East", "West")
    int position;          // Position of the vehicle approaching the intersection

public:
    // Constructor
    Vehicle(int id, const std::string& direction);

    // Getters
    int getId() const;
    std::string getDirection() const;
    int getPosition() const;

    // Advances the vehicle by one position
    void advance();
};

#endif // VEHICLE_H
