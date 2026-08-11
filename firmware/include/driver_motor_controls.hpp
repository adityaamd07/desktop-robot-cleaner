#ifndef DRIVER_MOTOR_CONTROLS_HPP
#define DRIVER_MOTOR_CONTROLS_HPP

#include <Arduino.h> 

//PIN DEFINITIONS FOR L293D
#define MOTOR_LEFT_INP_ONE  25
#define MOTOR_LEFT_INP_TWO  26
#define MOTOR_RIGHT_INP_ONE 27
#define MOTOR_RIGHT_INP_TWO 14
#define MOTOR_LEFT_SPEED    32
#define MOTOR_RIGHT_SPEED   33

#define MOTOR_LEFT_SPEED_CHANNEL 0
#define MOTOR_RIGHT_SPEED_CHANNEL 1

//possible drive states for robot
enum class drive_state {STOPPED, FORWARD, BACKWARD, TURNING_LEFT, TURNING_RIGHT };

/**
 * driver_motor_controls represents the two wheel differential of the desktop cleaner robot. 
 * It uses two GA12-N20 motors and an L293D
 * 
 * Abstraction Function: 
 * AF(drive_state): current physical state of the robot's two drivetrain wheels in the 
 * present moment. 
 * 
 * Representation Invariants: 
 *  - current_state is always one of the defined drive state values
 *  - To avoid shorting L293D, both input pins of a single motor may never be 
 *    set to HIGH 
 **/


class driver_motor_controls {
    public:
       
        // constructor written for peace of mind
        driver_motor_controls();

        //defines all GPIO pins as OUTPUT, then sets the current driver state to stop
        void begin();

        //MOTOR OPERATIONS:
        void forward();
        void backward();
        void turn_left();
        void turn_right();
        void stop();
        void set_speed();
        drive_state get_state();
    private:
        drive_state current_state;
        
};
#endif
