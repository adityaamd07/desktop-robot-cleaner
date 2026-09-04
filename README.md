# desktop-robot-cleaner
The goal of this project is for myself, a rising sophomore mechanical engineering student, to create a desktop cleaning with autonomous capabilities. The individual goals and markers of this project have changed quite a bit since its inception in May, but I have learned quite a bit by doing this and it has been a lot of fun!

**Project Status:** In progress: 

## Project accomplishments, current happenings, and future goals 
Since the project's start I have done the following: 
- Designed and fabricated a 7" circular chassis, ensuring that the chassis is able to fit tight space constraints between all components
- Designed a Scotch Yoke mechanism to move a cleaning pad back and forth, effectively sweeping areas. 
- Selected the proper materials, including chassis make, sensors, motors, and main chip driving performance
- Breadboard tested and permanently soldered components, utilizing IC sockets, screw terminals, and multmeter testing to ensure connectivity. 
- Designed a C++ firmware architecture using PlatformIO to have manual drive and sweeping capabilities

I am currently doing the follwing: 
- Attempting to synthesize C++ firmware, physical mechanisms, and electrical components together in one working system 
  by using the ESP32's bluetooth capabilities to handle manual driving and sweeping

Future Goals/Ideas: 
- Redesign chassis to be a 7"x 7" square, which will result in better use of space as many components are rectangular in nature
- Add autonomous capabilities
    - IMU + Encoders? 
    - Something else??
- Introduce a spray mechanism so the robot can sanitize a surface and sweep it in one pass. 


## Repo Structure: 
- docs
    - media: For all photos and vidoes I take during the project
    - sketches: a folder of all planning sketches I do for this project. To me, a planning sketch is one that I do simply to view an overall layout. Crucially, it does NOT have any dimensions. 
    - design_decisions: A log of decisions made throughout this project, including the rationale behind these decisions
    - materials purchased: a bill of all things bought for this project in order to keep tally of budget
    - components_list: a list of all components necessary for this project, both purchased and not yet acquired.
    - current: a planning document to organize tasks I need to accomplish in a given day, and the following days and week
- hardware: 
    - Chassis: all CAD models or engineering drawings including the full robot chassis
    - cleaning mechanism: all CAD models or engineering drawings/reasonings relating to the cleaning mechanism
- firmware: Used platformio in VSCODE
    - include: contains headerfiles
    - lib: any imported libraries
    - src: all source code
    - test: any test code
    - pio/build: ESP32 files preloaded by platformio
    - vscode: json files preloaded by vscode




