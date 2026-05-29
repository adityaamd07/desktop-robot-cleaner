| Component name | Purpose | Quantity needed | Operating Voltage | Max Current Draw | Comment | 
| --- | --- | :---: | :-----: | :--: | --- | 
| ESP32 DevBoard | Microcontroller | 1 | 5-7 | 500 mA (conservative estimate) | Component included in ELEGOO starter kit | 
| Ultrasonic sensor | Detect objects directly in front of robot | 1 | Component included in ELEGOO starter kit. Will likely place one sensor in front of robot, with no need for more ( may change) | 
| IR Line Sensor | Detect surface (and lack thereof) underneath robot | 2-3? | Must draw sketch to decide how many sensors I need | 
| Step Motor 28BJY-48 | Source of Motion for Scubbing Mechanism | 1 | 5V | 240mA (highest estimate) | Component included in ELEGOO starter kit | 
| ULN2003 Stepper Motor Driver Module | Driver board for Step Motor | 1 | 5V | negligable | Component included in ELEGOO starter kit
| G12-N20 DC Driver Motors | Turn Wheels | 2 (ordered 3) | 6 | 0.67 A each | I have not thought about sanitizing pump so far, but I could potentially drive it with this extra motor |
| L293D Motor Driver | DC Motor Driver Board | 1 (so far) | Maximum Voltage of 36V | 1.2 peak output | This component wil likely need replacing as it may not be able to provide enough current if a motor stalls. That said, it came with the ELEGOO kit so I am fine to using for prototyping for now. Additionally, I will likley need an additional motor driver to drive the sanitizing pump | 

