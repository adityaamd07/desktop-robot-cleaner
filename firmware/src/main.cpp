#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

int motor_one_input_one = 21;
int motor_one_input_two = 22;

void setup() {
pinMode(motor_one_input_one, OUTPUT);
pinMode(motor_one_input_two, OUTPUT);
}

void loop() {
 
digitalWrite(motor_one_input_one, HIGH);
digitalWrite(motor_one_input_two, HIGH);

delay(5000);

digitalWrite(motor_one_input_one, LOW);
digitalWrite(motor_one_input_two, LOW);

delay(5000);

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}