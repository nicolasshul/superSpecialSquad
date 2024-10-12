#ifndef KINEMATICS_MAPPING_H
#define KINEMATICS_MAPPING_H

const float SIN45 = 0.70710678;
const float COS45 = 0.70710678;
const float WHEEL_RADIUS = 2;
const float WHEEL_DIST = 2;
const float MAX_SPEED = 20;

struct Wheel_Velos {
    float wheel_one_speed;
    float wheel_two_speed;
    float wheel_three_speed;
    float wheel_four_speed;
};

struct Input {
    float x_velo;
    float y_velo;
    float ang_velo;
};

float max(float x, float y);
void updateWheelVelocity(struct Wheel_Velos* velos, struct Input* input);
void desaturate(struct Wheel_Velos* velos);

#endif //  KINEMATICS_MAPPING_H