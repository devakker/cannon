//
// Created by spinakker on 10/15/2019.
//

#ifndef CANNON_CANNON_H
#define CANNON_CANNON_H

#define GRAV_ACC 9.81

typedef struct Vector {
    double x;
    double y;
} Vector;

typedef struct State {
    Vector position;
    Vector speed;
} State;

Vector initialSpeed;

Vector ConvertToVector(double length, double angle);
State GetStateAt(double time);
double deg2rad(double degrees);

#endif //CANNON_CANNON_H
