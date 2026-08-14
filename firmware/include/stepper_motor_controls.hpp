#ifndef STEPPER_MOTOR_CONTROLS_HPP
#define STEPPER_MOTOR_CONTROLS_HPP

#include <Arduino.h>


//PIN DEFINITIONS
#define IN1 4
#define IN2 13
#define IN3 21
#define IN4 23

enum class sweep_state {SWEEPING, STOPPED, RESETTING};


/**
 * stepper motor controls represents the cleaning mechanism of the robot by programming the 
 * stepper motor of the robot to rotate 180 degrees one direction, and 180 degrees back in the other direction.
 * It uses an ULN2003 with a 28BYJ-48 Stepper Motor.
 * 
 * Abstraction Function: 
 * AF(stepper_state): Represents the specific state of the stepper motor, either sweeping or stopped. 
 * 
 * Representation Invarient:
 *  - stepper_state is always one of the defined states * 
 *  - the stepper motor always rotates counter clockwise from position 0 to position 180, and 
 *    counter clockwise from position 180 to position 0
 */

 class stepper_motor_controls {

    public:

        stepper_motor_controls();

        //assigned above pin definition as output
        void begin();

        void start_sweep();

        //defines one half sweep motion, back and forth
        void sweep(unsigned long ms);

        //stops all motion of stepper motor
        void stop();

        //resets stepper motor to defined starting position of motor
        void reset();

        sweep_state get_state();

    private:

        static constexpr uint8_t step_sequence[8][4] = {
            {1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,1,1,0},
            {0,0,1,0}, {0,0,1,1}, {0,0,0,1}, {1,0,0,1}
        }; // matrix of all the pinout combinations to make the stepper motor spin 
           // static because all stepper motor classes will use this same table, 
           // constexpr to make sure that table is generated at compile time and never reassigne,
           //uint8_t is an 8 bit int type (used as a memory saver)

        void step_once(int direction);
        int step_index;
        int steps_taken;

        sweep_state current_state; //keeps track of state of cleaning mechanism
        const int steps_per_rotation = 4096; //per documentation found online
        const int interval = 2; //per step interval for this stepper motor
        int direction_sign;  // determines direction of the stepper motor
        unsigned long prev_ms; //used for per step delay of stepper motor
        int current_position;

        //built in margin safety in case 180 degrees of rotation is too much for mechanism
        const int margin = 8;
        const int max_steps = (int) (((180.0 - margin) / 360.0) * steps_per_rotation);



 };

#endif
