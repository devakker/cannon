//
// Created by spinakker on 10/15/2019.
//

#include <math.h>
#include "cannon.h"

Vector initialSpeed;


static State CalculateStateAt(double time) {
    State state;
    state.position.x = initialSpeed.x * time;
    state.position.y = initialSpeed.y * time - GRAV_ACC / 2 * time * time;
    state.speed.x = initialSpeed.x;
    state.speed.y = initialSpeed.y - GRAV_ACC * time;
    return state;
}

State GetStateAt(double time) {
    State state = CalculateStateAt(time);
    return state;
}

Vector ConvertToVector(double length, double angle) {
    Vector result;
    result.x = length * cos(deg2rad(angle));
    result.y = length * sin(deg2rad(angle));
    return result;
}

double GetLengthOfVector(Vector vector) {
    double length = sqrt(vector.x * vector.x + vector.y * vector.y);
    return length;
}


double deg2rad(double degrees) {
    return degrees * M_PI / 180;
}
