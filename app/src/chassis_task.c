#include "chassis_task.h"

#include "robot.h"
#include "remote.h"
#include <dji_motor.h>

extern Robot_State_t g_robot_state;
extern Remote_t g_remote;
DJI_Motor_Handle_t *motor_w1;
DJI_Motor_Handle_t *motor_w2;
DJI_Motor_Handle_t *motor_w3;
DJI_Motor_Handle_t *motor_w4;

float chassis_rad;

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
        .angle_pid =
            {
                .kp = 5000.0f,
                .kd = 3500000.0f,
                .ki = 0.1f,
                .output_limit = M2006_MAX_CURRENT,
                .integral_limit = 1000.0f,
            }
    };
    motor_w1 = DJI_Motor_Init(&chassis_w1, M2006);

    Motor_Config_t chassis_w2 = {
        .can_bus = 2, // change later 
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
        .angle_pid =
            {
                .kp = 5000.0f,
                .kd = 3500000.0f,
                .ki = 0.1f,
                .output_limit = M2006_MAX_CURRENT,
                .integral_limit = 1000.0f,
            }
    };
    motor_w2 = DJI_Motor_Init(&chassis_w2, M2006);

    Motor_Config_t chassis_w3 = {
        .can_bus = 3, // change later 
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
        .angle_pid =
            {
                .kp = 5000.0f,
                .kd = 3500000.0f,
                .ki = 0.1f,
                .output_limit = M2006_MAX_CURRENT,
                .integral_limit = 1000.0f,
            }
    };
    motor_w3 = DJI_Motor_Init(&chassis_w3, M2006);

    Motor_Config_t chassis_w4 = {
        .can_bus = 4, // change later 
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
        .angle_pid =
            {
                .kp = 5000.0f,
                .kd = 3500000.0f,
                .ki = 0.1f,
                .output_limit = M2006_MAX_CURRENT,
                .integral_limit = 1000.0f,
            }
    };
    motor_w4 = DJI_Motor_Init(&chassis_w4, M2006);
}

void Chassis_Ctrl_Loop()
{
    // Control loop for the chassis
}