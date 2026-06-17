| Component name | Purpose | Quantity needed | Operating Voltage | Max Current Draw |  Dimensions |  Comment | 
| --- | --- | :---: | :-----: | :--: | -- |  :--- | 
| ESP32 DevBoard | Microcontroller | 1 | 5-7 | 500 mA (conservative estimate) | 56x28x13 mm | Component included in ELEGOO starter kit | 
| Ultrasonic sensor | Detect objects directly in front of robot | 1 | 20x43x15 mm | Component included in ELEGOO starter kit. Will likely place one sensor in front of robot, with no need for more ( may change) | 
| IR Line Sensor | Detect surface (and lack thereof) underneath robot | 2 | N/A | N/A | 32x14 mm | ordered a pack of 5 as that was lowest amount I could find |  
| Step Motor 28BJY-48 | Source of Motion for Scubbing Mechanism | 1 | 5V | 240mA (highest estimate) | Component included in ELEGOO starter kit | 
| ULN2003 Stepper Motor Driver Module | Driver board for Step Motor | 1 | 5V | negligable | Component included in ELEGOO starter kit
| G12-N20 DC Driver Motors | Turn Wheels | 2 (ordered 3) | 6 | 0.67 A each | I have not thought about sanitizing pump so far, but I could potentially drive it with this extra motor |
| L293D Motor Driver | DC Motor Driver Board | 1 (so far) | Maximum Voltage of 36V | 1.2 peak output | This component wil likely need replacing as it may not be able to provide enough current if a motor stalls. That said, it came with the ELEGOO kit so I am fine to using for prototyping for now. Additionally, I will likley need an additional motor driver to drive the sanitizing pump | 
| OVONIC Lipo Battery 7.4v 1500mAh | Power for ESP32, Motor Drivers, and Power Supply Module | 1 | N/A | N/A | 125x21.5x12.5 mm | N/A | 
| Power Supply Module | Regulate Volage to Motor Driver and ESP 32 | 1 | N/A | N/A |  

