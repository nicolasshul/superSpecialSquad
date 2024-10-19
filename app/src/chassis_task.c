#include "chassis_task.h"

#include "robot.h"
#include "remote.h"
#include "dji_motor.h"
#include "omni_kinematics_mapping.h"

extern Robot_State_t g_robot_state;
extern Remote_t g_remote;
DJI_Motor_Handle_t *motor_w1;
DJI_Motor_Handle_t *motor_w2;
DJI_Motor_Handle_t *motor_w3;
DJI_Motor_Handle_t *motor_w4;

float chassis_rad;

struct Input controller_in = {
    .x_velo = 0,
    .y_velo = 0,
    .ang_velo = 0,
};

void Chassis_Task_Init()
{
    Motor_Config_t chassis_w1 = {
        .can_bus = 1, // change later 
        .speed_controller_id = 1, // change later based on can bus
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            { // tune later
                .kp = 100.0f,
                .kd = 20.0f,
                .kf = 20.0f,
                .output_limit = M2006_MAX_CURRENT,
            },
    };
    motor_w1 = DJI_Motor_Init(&chassis_w1, M2006);

    Motor_Config_t chassis_w2 = {
        .can_bus = 1, // change later 
        .speed_controller_id = 2, // change later based on can bus
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            { // tune later
                .kp = 100.0f,
                .kd = 20.0f,
                .kf = 20.0f,
                .output_limit = M2006_MAX_CURRENT,
            },
    };
    motor_w2 = DJI_Motor_Init(&chassis_w2, M2006);

    Motor_Config_t chassis_w3 = {
        .can_bus = 1, // change later 
        .speed_controller_id = 3, // change later based on can bus
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            { // tune later
                .kp = 100.0f,
                .kd = 20.0f,
                .kf = 20.0f,
                .output_limit = M2006_MAX_CURRENT,
            },
    };
    motor_w3 = DJI_Motor_Init(&chassis_w3, M2006);

    Motor_Config_t chassis_w4 = {
        .can_bus = 1, // change later 
        .speed_controller_id = 4, // change later based on can bus
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            { // tune later
                .kp = 100.0f,
                .kd = 20.0f,
                .kf = 20.0f,
                .output_limit = M2006_MAX_CURRENT,
            },
    };
    motor_w4 = DJI_Motor_Init(&chassis_w4, M2006);
}

void Chassis_Ctrl_Loop() // This is for the kinematics, everything else is handled in robot.c. Use Robot_State_t and Remote_ t structs
{
    // int16_t remote_vy = g_remote.controller.right_stick.y;
    // int16_t remote_vx = g_remote.controller.right_stick.x;
    // int16_t remote_rotation = g_remote.controller.left_stick.x;

    controller_in.x_velo = (float) (g_robot_state.input.vx / REMOTE_STICK_MAX);
    controller_in.y_velo = (float) (g_robot_state.input.vy / REMOTE_STICK_MAX);
    controller_in.ang_velo = (float) (g_robot_state.input.rotation / REMOTE_STICK_MAX);

    


}