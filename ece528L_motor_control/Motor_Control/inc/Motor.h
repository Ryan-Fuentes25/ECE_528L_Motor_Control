/**
 * @file Motor.h
 * @brief Header file for the Motor driver.
 *
 * This file contains the function definitions for controlling the DC motors using Pulse Width Modulation (PWM).
 * It provides functions for initializing the motor driver, controlling motor movement in various directions,
 * adjusting motor speed with PWM, and stopping the motors.
 *
 * @author Aaron Nanas
 *
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include <stdint.h>
#include "msp.h"
#include "../inc/CortexM.h"
#include "../inc/Timer_A0_PWM.h"

/**
 * @brief Initialize the DC motor driver pins and Timer A0 PWM.
 *
 * This function configures P5.4 (left motor direction) and P5.5 (right motor direction) as GPIO output pins,
 * and P3.6 (right motor sleep) and P3.7 (left motor sleep) as GPIO output pins. All four outputs start at 0.
 * Then, it initializes Timer A0 with a period of 20 ms (period constant of 15000) and 0% duty cycles.
 *
 * @param None
 *
 * @return None
 */
void Motor_Init();

/**
 * @brief Moves the motors forward with specified duty cycles.
 *
 * This function configures the motors to move in a forward direction by setting the appropriate GPIO pins.
 * It also updates the duty cycle for both left and right motors using Timer A0 PWM control to adjust motor speed.
 *
 * @param left_duty_cycle The duty cycle for the left motor (0-99%).
 *
 * @param right_duty_cycle The duty cycle for the right motor (0-99%).
 *
 * @return None
 */
void Motor_Forward(uint16_t left_duty_cycle, uint16_t right_duty_cycle);

/**
 * @brief Move the motors backward with specified duty cycles.
 *
 * This function configures both motors to move backward. It updates the duty cycle for both left
 * and right motors using Timer A0 PWM control to adjust motor speed.
 *
 * @param left_duty_cycle The duty cycle for the left motor (0-99%).
 *
 * @param right_duty_cycle The duty cycle for the right motor (0-99%).
 *
 * @return None
 */
void Motor_Backward(uint16_t left_duty_cycle, uint16_t right_duty_cycle);

/**
 * @brief Turn the robot to the left with specified duty cycles.
 *
 * This function sets the left motor to move backward and the right motor to move forward.
 * It updates the duty cycle for both motors using Timer A0 PWM control and enables the motors.
 *
 * @param left_duty_cycle The duty cycle for the left motor (0-99%).
 *
 * @param right_duty_cycle The duty cycle for the right motor (0-99%).
 *
 * @return None
 */
void Motor_Left(uint16_t left_duty_cycle, uint16_t right_duty_cycle);

/**
 * @brief Turn the robot to the right with specified duty cycles.
 *
 * This function sets the left motor to move forward and the right motor to move backward.
 * It updates the duty cycle for both motors using Timer A0 PWM control and enables the motors.
 *
 * @param left_duty_cycle The duty cycle for the left motor (0-99%).
 *
 * @param right_duty_cycle The duty cycle for the right motor (0-99%).
 *
 * @return None
 */
void Motor_Right(uint16_t left_duty_cycle, uint16_t right_duty_cycle);

/**
 * @brief Stop the motors and set the duty cycle to 0%.
 *
 * This function disables both motors, effectively stopping them, and sets the duty cycle for both motors to 0%.
 *
 * @return None
 */
void Motor_Stop();

#endif /* INC_MOTOR_H_ */
