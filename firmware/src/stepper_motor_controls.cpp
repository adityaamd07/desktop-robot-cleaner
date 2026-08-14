#include "stepper_motor_controls.hpp"



stepper_motor_controls :: stepper_motor_controls() : current_state(sweep_state :: STOPPED),
                                                interval(500), direction_sign (1), prev_ms(0), 
                                                steps_taken(0), step_index(0), current_position(0) {}


void stepper_motor_controls :: step_once(int direction) {

    step_index = (step_index + direction + 8 ) % 8;
    digitalWrite(IN1, step_sequence[step_index][0]);
    digitalWrite(IN2, step_sequence[step_index][1]);
    digitalWrite(IN3, step_sequence[step_index][2]);
    digitalWrite(IN4, step_sequence[step_index][3]);
    current_position += direction;


}
void stepper_motor_controls :: begin() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
    current_state = sweep_state :: STOPPED;
}

void stepper_motor_controls :: sweep(unsigned long ms) {

    if(ms - prev_ms <= interval){ // not enough time has passed since last step, ignore this call
        return;
    }
    prev_ms = ms; //enough time has passed, reset prev_ms
    
    switch(current_state){ //handling between the three cases

        case (sweep_state :: SWEEPING) : 
            
            //takes once step forward
            step_once(direction_sign);
            steps_taken++;

            //checks if we have done the first half of rotation, and reverses direction
            if(steps_taken > max_steps ){

                direction_sign *= -1;
                steps_taken = 0;
            }
            break;

        case (sweep_state :: STOPPED) : 
            //do nothing
            break;
        
        case (sweep_state :: RESETTING) :
            
            if(current_position != 0){ //decide on which direction to travel based on number of steps taken thus far
                direction_sign = -1;
                step_once(direction_sign);
            }else {
                stop();
            }
            break;
    }
}

void stepper_motor_controls :: start_sweep() {
    current_state = sweep_state :: SWEEPING;
}

void stepper_motor_controls :: reset() {
    current_state = sweep_state :: RESETTING;
}

sweep_state stepper_motor_controls :: get_state() {
    return current_state;
}
void stepper_motor_controls :: stop() {

    current_state = sweep_state :: STOPPED;
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

}