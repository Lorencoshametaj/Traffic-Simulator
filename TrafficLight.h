#pragma once
#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <string>

// Class representing a traffic light
class TrafficLight {
public:
    // Enumeration of possible light states
    enum LightState { RED, YELLOW, GREEN };

private:
    LightState state;   // Current state of the traffic light
    int timer;          // Remaining time in the current state
    int redDuration;    // Duration of the red light
    int yellowDuration; // Duration of the yellow light
    int greenDuration;  // Duration of the green light

public:
    // Constructor
    TrafficLight(int redDuration, int yellowDuration, int greenDuration);

    // Updates the traffic light state based on the timer
    void update();

    // Returns the current state of the traffic light
    LightState getState() const;

    // Returns the current state as a string
    std::string getStateAsString() const;
};

#endif // TRAFFICLIGHT_H
