#include "TrafficLight.h"

// Constructor implementation
TrafficLight::TrafficLight(int redDuration, int yellowDuration, int greenDuration)
    : redDuration(redDuration), yellowDuration(yellowDuration), greenDuration(greenDuration), state(RED), timer(redDuration) {}

// Updates the traffic light state and timer
void TrafficLight::update() {
    timer--;
    if (timer <= 0) {
        switch (state) {
        case RED:
            state = GREEN;
            timer = greenDuration;
            break;
        case GREEN:
            state = YELLOW;
            timer = yellowDuration;
            break;
        case YELLOW:
            state = RED;
            timer = redDuration;
            break;
        }
    }
}

// Returns the current state of the traffic light
TrafficLight::LightState TrafficLight::getState() const {
    return state;
}

// Returns the current state as a string for display purposes
std::string TrafficLight::getStateAsString() const {
    switch (state) {
    case RED:
        return "RED";
    case YELLOW:
        return "YELLOW";
    case GREEN:
        return "GREEN";
    default:
        return "";
    }
}
