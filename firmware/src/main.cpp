#include <Arduino.h>

#include "driver_motor_controls.hpp"
#include "sensor_controls.hpp"
#include "stepper_motor_controls.hpp"
#include "web_server.hpp"


const char* WIFI_SSID = "Pramod's iPhone";
const char* WIFI_PASSWORD = "sadmonkey26";

web_server server(WIFI_SSID, WIFI_PASSWORD);

drive_state last_state = drive_state::STOPPED;

void setup() {

Serial.begin(115200);
delay(1000);

    Serial.println("Starting WebController...");
   server.begin();  // connects WiFi, registers routes, starts server
    Serial.println("Ready. Try visiting the routes below in a browser.");
}

void loop() {
    server.update();  // watchdog check -- runs every pass, no exceptions

    drive_state current = server.get_current_command();

    // Only print when the state actually changes, so you get a clean log
    // instead of hundreds of identical lines per second
    if (current != last_state) {
        Serial.print("Command changed to: ");
        switch (current) {
            case drive_state::STOPPED:  Serial.println("STOPPED");  break;
            case drive_state::FORWARD:  Serial.println("FORWARD");  break;
            case drive_state::BACKWARD: Serial.println("BACKWARD"); break;
            case drive_state::TURNING_LEFT:     Serial.println("TURNING_LEFT");     break;
            case drive_state::TURNING_RIGHT:    Serial.println("TURNING_RIGHT");    break;
        }
        last_state = current;
    }

    // No delay() here on purpose -- this loop needs to spin fast so the
    // watchdog timeout (400ms) gets checked frequently and accurately.
}
