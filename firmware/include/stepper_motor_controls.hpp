#ifndef STEPPER_MOTOR_CONTROLS_HPP
#define STEPPER_MOTORS_CONTROLS_HPP

#include <Arduino.h>

//PIN DEFINITIONS
#define IN1 4
#define IN2 13
#define IN3 21
#define IN4 23

enum class sweep_state {SWEEPING, STOPPED};


/**
 * stepper motor controls represents the cleaning mechanism of the robot by programming the 
 * stepper motor of the robot to rotate 180 degrees one direction, and 180 degrees back in the other direction.
 * It uses an ULN2003 with a 28BYJ-48 Stepper Motor.
 * 
 * Abstraction Function: 
 * AF(stepper_state): Represents the specific state of the stepper motor, either sweeping or stopped. 
 * 
 * Representation Invarient:
 *  -stepper_state is always one of the defined states * 
 */

 class stepper_motor_controls {

    public:

        stepper_motor_controls();

        //assigned above pin definition as output
        void begin();

        //defines one full sweep motion, back and forth
        void sweep();

        //stops all motion of stepper motor
        void stop();

        //resets stepper motor to defined starting position of motor
        void reset();

    private:
        sweep_state current_state;
        const int initial_position = 0;
 };

#endif
