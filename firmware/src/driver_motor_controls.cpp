#include "driver_motor_controls.hpp"


driver_motor_controls :: driver_motor_controls() : current_state(drive_state::STOPPED) {}

void driver_motor_controls :: begin() {

    pinMode(MOTOR_LEFT_INP_ONE, OUTPUT);
    pinMode(MOTOR_LEFT_INP_TWO, OUTPUT);
    pinMode(MOTOR_RIGHT_INP_ONE, OUTPUT);
    pinMode(MOTOR_RIGHT_INP_TWO, OUTPUT);
    
    ledcSetup(MOTOR_LEFT_SPEED_CHANNEL, 5000, 8);
    ledcAttachPin(MOTOR_LEFT_SPEED, MOTOR_LEFT_SPEED_CHANNEL);

    ledcSetup(MOTOR_RIGHT_SPEED_CHANNEL, 5000, 8);
    ledcAttachPin(MOTOR_RIGHT_SPEED, MOTOR_RIGHT_SPEED_CHANNEL);

    ledcWrite(MOTOR_LEFT_SPEED_CHANNEL, 255);
    ledcWrite(MOTOR_RIGHT_SPEED_CHANNEL, 255);
}
drive_state driver_motor_controls :: get_state () {
    return current_state;
}

void driver_motor_controls :: forward() {

    current_state = drive_state :: FORWARD;
    //LEFT MOTOR CONTROLS
    digitalWrite(MOTOR_LEFT_INP_ONE, HIGH);
    digitalWrite(MOTOR_LEFT_INP_TWO, LOW);

    //RIGHT MOTOR CONTROLS
    digitalWrite(MOTOR_RIGHT_INP_ONE, HIGH);
    digitalWrite(MOTOR_RIGHT_INP_TWO, LOW);

}

void driver_motor_controls :: backward() {


    current_state = drive_state :: BACKWARD;

    //LEFT MOTOR CONTROLS
    digitalWrite(MOTOR_LEFT_INP_ONE, LOW);
    digitalWrite(MOTOR_LEFT_INP_TWO, HIGH);

    //RIGHT MOTOR CONTROLS 
    digitalWrite(MOTOR_RIGHT_INP_ONE, LOW);
    digitalWrite(MOTOR_RIGHT_INP_TWO, HIGH);

}

void driver_motor_controls :: turn_left() {

    current_state = drive_state :: TURNING_LEFT;

    //LEFT MOTOR
    digitalWrite(MOTOR_LEFT_INP_ONE, LOW);
    digitalWrite(MOTOR_LEFT_INP_TWO, LOW);

    //RIGHT MOTOR
    digitalWrite(MOTOR_RIGHT_INP_ONE, HIGH);
    digitalWrite(MOTOR_RIGHT_INP_TWO, LOW);

}

void driver_motor_controls :: turn_right() {

    current_state = drive_state :: TURNING_RIGHT;

    //LEFT MOTOR
    digitalWrite(MOTOR_LEFT_INP_ONE, HIGH);
    digitalWrite(MOTOR_LEFT_INP_TWO, LOW);

    //RIGHT MOTOR
    digitalWrite(MOTOR_RIGHT_INP_ONE, LOW);
    digitalWrite(MOTOR_RIGHT_INP_TWO, LOW);

}
void driver_motor_controls :: stop() {

    current_state = drive_state :: STOPPED;

    //LEFT MOTOR
    digitalWrite(MOTOR_LEFT_INP_ONE, LOW);
    digitalWrite(MOTOR_LEFT_INP_TWO, LOW);

    //RIGHT MOTOR 
    digitalWrite(MOTOR_RIGHT_INP_ONE, LOW);
    digitalWrite(MOTOR_RIGHT_INP_TWO, LOW);
}

drive_state driver_motor_controls :: get_state() {
    return current_state;
}
