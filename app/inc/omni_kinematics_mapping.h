#ifndef OMNI_KINEMATICS_MAPPING_H
#define OMNI_KINEMATICS_MAPPING_H

#define SIN45 0.70710678
#define COS45 0.70710678
#define WHEEL_RADIUS 2.0f
#define WHEEL_DIST 2.0f
#define MAX_SPEED 600.0f

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

float max(struct Wheel_Velos* velos);
void updateWheelVelocity(struct Wheel_Velos* velos, struct Input* input);
void desaturate(struct Wheel_Velos* velos);

#endif //  KINEMATICS_MAPPING_H