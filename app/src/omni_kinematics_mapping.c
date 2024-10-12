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
    velos->wheel_one_speed = (1 / WHEEL_RADIUS) * (SIN45 * input->x_velo + -COS45 * input->y_velo + WHEEL_DIST * input->ang_velo);
    velos->wheel_one_speed = (1 / WHEEL_RADIUS) * (COS45 * input->x_velo + SIN45 * input->y_velo + WHEEL_DIST * input->ang_velo);
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
