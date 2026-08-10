# desktop-robot-cleaner
The goal of this project is for myself, a rising sophomore mechanical engineering student, to create a fully autonomous desktop robot that is able sweep and sanitize a smooth, rectangular surface in one pass. This is obviously very ambitious for someone with zero experience in design or electronics. Although I have experience in C++, this will still prove to be a challenge. Thus, I have divided this project into two seperate phases, each with its own goals.

## Phase one: Robot driving mechanism

The goal of this phase is to create a fully functioning drivable robot with a sweeping mechanism a. The robot should be able to drive in all four cardinal directions with human input, and should be able to turn the sweeping mechanism with human input. 

**Status:** ongoing 

## Phase two: Autonomous driving and spraying mechanism

This phase will involve fully designing and testing my autonomous driving system, and adding the spraying mechanism to my robot. I will consider this phase, and therefore the project, a success if the robot can autonomously sweep and sanitize the surface without falling off the edge of the desk, crashing, stopping for a super prolonged period of time, or crashing into any of the objects on the surface. 

**Status:** not started

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

**(Self-Imposed) Phase 1 Deadline:** August 30th (The day before classes start)
**Current Project Status:** Designing robot chassis, cleaning mechanism, and electrical components layout



