#include "omni_kinematics_mapping.h"

float max(float x, float y) {
    if (x > y) {
        return x;
    }
    else {
        return y;
    }
}

void updateWheelVelocity(struct Wheel_Velos* velos, struct Input* input) {
    velos->wheel_one_speed = (1 / WHEEL_RADIUS) * (-SIN45 * input->x_velo + COS45 * input->y_velo + WHEEL_DIST * input->ang_velo);
    velos->wheel_two_speed = (1 / WHEEL_RADIUS) * (-COS45 * input->x_velo + -SIN45 * input->y_velo + WHEEL_DIST * input->ang_velo);
    velos->wheel_three_speed = (1 / WHEEL_RADIUS) * (SIN45 * input->x_velo + -COS45 * input->y_velo + WHEEL_DIST * input->ang_velo);
    velos->wheel_four_speed = (1 / WHEEL_RADIUS) * (COS45 * input->x_velo + SIN45 * input->y_velo + WHEEL_DIST * input->ang_velo);
}

void desaturate(struct Wheel_Velos* velos) {
    float highest_speed = max(velos->wheel_one_speed, max(velos->wheel_two_speed, max(velos->wheel_three_speed, velos->wheel_four_speed)));
    if (highest_speed > MAX_SPEED) {
        float ratio = MAX_SPEED / highest_speed;
        velos->wheel_one_speed = velos->wheel_one_speed * ratio;
        velos->wheel_two_speed = velos->wheel_two_speed * ratio;
        velos->wheel_three_speed = velos->wheel_three_speed * ratio;
        velos->wheel_four_speed = velos->wheel_four_speed * ratio;

    }
}
