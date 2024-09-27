#include "Vehicle.h"

// Constructor implementation
Vehicle::Vehicle(int id, const std::string& direction)
    : id(id), direction(direction), position(0) {}

// Returns the vehicle's ID
int Vehicle::getId() const {
    return id;
}

// Returns the vehicle's direction
std::string Vehicle::getDirection() const {
    return direction;
}

// Returns the vehicle's current position
int Vehicle::getPosition() const {
    return position;
}

// Advances the vehicle by incrementing its position
void Vehicle::advance() {
    position++;
}
