#include "sensor_controls.hpp"

sensor_controls :: sensor_controls() {}


void sensor_controls :: begin(){
    pinMode(ULTRASONIC_TRIG, OUTPUT);
    pinMode(ULTRASONIC_ECHO, INPUT);
    pinMode(IR_FRONT_PIN, INPUT);
    pinMode(IR_BACK_PIN, INPUT);
    
}

bool sensor_controls :: does_floor_exist() {

    return does_floor_exist_front() && does_floor_exist_back();

}

bool sensor_controls :: is_obj_close() {

    return ultrasonic_distance() < threshold;

}

float sensor_controls :: ultrasonic_distance() {

    //sets TRIG to low, then sends sustained, ultrasonic pulses out
    digitalWrite(ULTRASONIC_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONIC_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIG, LOW);

    //duration is the amount of time it takes for echo pin to switch from HIGH 
    //back to low
    long duration = pulseIn(ULTRASONIC_ECHO, HIGH, 30000); 

    return (duration * 0.0343) / 2; //distance = speed * time, so multiple duration by speed of sound (343 m/s)
                                    //since duration is for the pulse to reach object and back, divide by 2 to get half the trip
}

bool sensor_controls :: does_floor_exist_front() {

    return !digitalRead(IR_FRONT_PIN);

}

bool sensor_controls :: does_floor_exist_back() {
    return !digitalRead(IR_BACK_PIN);
}