#ifndef SENSOR_CONTROLS_HPP
#define SENSOR_CONTROLS_HPP

#include <Arduino.h>



//Pin Definitions
#define ULTRASONIC_TRIG 18
#define ULTRASONIC_ECHO 19
#define IR_FRONT_PIN    16
#define IR_BACK_PIN     17
/**
 * sensor controls gets and stores the information sent by the sensors of the desktop cleaning robot. The robot currently uses two
 * TCRT5000 IR sensors and 1 HC-SR04 Ultrasonic Sensor
 * 
 * This class is stateless, and does not hold any stored sensor readings. Every public method triggers a fresh hardware read. 
 * 
 * Abstraction Function: none
 * 
 *  Rep Invariant: none 
 */
class sensor_controls{
    public:
        // constructor written for peace of mind
        sensor_controls();

        //sets GPIO pins defined above as input pins
        void begin();

        bool is_obj_close();

        bool does_floor_exist();
    private: 

        
        float ultrasonic_distance();//returns current distance reading of an object
        bool does_floor_exist_front(); //returns front reading of IR sensor
        bool does_floor_exist_back(); // return back sensor of IR sensor
        const int threshold = 5; //threshold for when an object is too close for 
                                 //ultrasonic sensor (in cm)


};
#endif