# Design Decision Log

## Robot Chassis Shape -- 5/4/26
To begin this project, I considered two main shapes for the robot chassis: 

- Rectangular
- Circular 

I initially considered the rectangular shape because, to me, it simply made the most sense. 
Most of the electronic components are rectangular in shape, and it would be the most space 
efficient to have the robot be a rectangle, as then each component could slot in nicely. 
This has problems though: a rectangle is not as easy to maneuver as a circle, and for this robot to be autonomous,
it would have to be able to make fine tune adjustments in its position, which is much more difficult for a box to manage. 
Additionally, a rectangular shape would also likely require four wheels, would significantly increase the cost of the project, 
which is something I would like to avoid. The circular shape is less space efficient, 
but it is much superior in its maneuverability, which will make my life a lot easier when it comes to making this thing 
autonomous. According to my initial block sketches, the circle should contain enough space to properly manage components, 
and I can definitely find ways to make use of the shape to my advantage. 

**Decision:** Circular Chassis

## Chassis Diameter - 5/5/26
I considered a 6 in, 7 in, and 8 in diameter for the robot size. To determine the size that felt right for my desk, I drew a circle of 6, 7, and 8 in diameter on a sheet of paper and look at their relative size compared to my desk. I decided that 7 in would leave enough room for electrical components, while simultaneously allowing for enough manuverability for a desk my size. 
**Decision:** 7 inch diameter for chassis

## Robot Scrubbing Mechanism -- 5/5/26
I explored two options today of how to scrub the surface of its materials. The first option I considered is a rotating shaft that is in contact with the surface at all times. This design idea presented problems, however. Firstly, this rotating shaft would likely have to be a brush, not a dusting pad. A rotating dusting pad, to me, is not an effective way to clean, as the dirt is more likely to simply be spread out more rather than actually be collected. This, however, presented its own challenges. Even if I decided to do a brush, I would still likely need a dust  collection system so that the dirt is removed from the surface. This is much more mechanically complex, but also this is not very feasible to combine into a the second stage: santizing. How could I possible turn this dust collection system into a sanitizer? Suddennly, this begins to sound like two different machines.

The second option I considered is a oscillating dusting pad that is in constant contact with the surface. This option to me seems the better option. A scrubber that moves back and forth is much more intuitive, as that is how a normal person would dust a surface: scrubbing a swiffer back and forth. And, by using a swiffer pad specifically designed to collect dirt, I would rid the need of a dust collection system. This ties perfectly into the sanitizing stage: people sanitize surfaces by moving a clorax wipe or an equivalent back and forth, so it makes sense for a robot to do that as well. So, after dusting and removing larger debris, I can simply replace the dusting pad with a small mop pad, and my robot will instead turn into a sanitizer. 

**Decision:** An oscillating dusting that scrubs that surface back and forth

Further Questions for next steps: 
- How will I make the pad oscillate back and forth? The only way I know of to make things move in a robot is a motor. Is there any other way? Otherwise, how do I turn rotational motion into linear?
- How will I attach these pads to the robot?
- How will I change out these pads?

## Overall Drive train decision -- 5/11/26
I considered a few  options for my vehicle drivetrain, or how to actually get my robot moving. The first idea was to model my robot after a car: four wheels, two in the front and two in the back, each connected with a rotating shaft. I had considered using one motor to drive one of the wheel-shaft combo, but then quickly realized that I would have no way to turn the car. I then researched how a modern car handles steering: a rack and pinion setup connected to a steering wheel that would angle the wheels 

This was definitely interesting, but I deemed it far too mechanically complex for what I am trying to accomplish. Besides, this idea would require buying four wheels, which would increase cost. I then considered both a two and three wheel design. The two wheel design would be realtively simple: two wheels, one on each side of the chassis, each connected to a DC motor. These wheels would not be connected to a central shaft, but would fall in line along the diameter of the robot. This would allow for easy manuervering, as turning the robot would be as easy as turning one of the motors on and the other off. 

I also briefly considered a 3 wheel design. This would keep the two wheel system, but add a third castor wheel towards the front of the robot in order to achieve greater stability. For this design, I could either keep the two wheels at the diameter, or shift it further back, along a chord of the circle. For now, I will pocket this design. I plan to have the scrubbing mechanism in constant contact with the surface, so that _should_ provide enough stability for the robot to tip over. I will move forward with planning and building an initial prototype, and then after some testing, I will decide whether a castor wheel is necessary. 

**Decision:** two wheel drivetrain with each wheel connected to its own motor

**Further Questions:**
 - Given that I know what my wheels system looks like, can I begin writing code for driving the robot, assuming manual inputs?
 - I previously decided on an oscillating system to scrub. Where should I place this system? The front? The back?
 - Should I have two levels in my robot, or is one enough for the components I need?

## Chassis Layout Planning -- 5/14/26
I worked in MS Paint today to plan out my chassis, working through placing different components in my circular frame. I have arranged a preliminary layout, which can be found docs/sketches. The main thing I wanted to figure out was how to fit in the scrubbing mechanism, and the answer is that I have no answer. I need to decide on a scrubbing mechanism, and come up with sketches before I can go any further. I have some ideas on a way to lower the srubbing mechanism further down below the chassis floor, thus making leaving much more space on the chassis itself for other components. 

No decision made today. Any Further Question mainly revolves around how I am going to design this scrubbing mechanism. 

## Scrubbing Mechanism Sketching --5/21/26
I used a penci, a piece of paper, and a ruler to sketch out and define my mechanism. These sketches are visible in the hardware folder. I worked through many things. Firstly, I decided to use velcro command strips in order to attach the cleaning pads (duster or mop pad) to the mount. This allows for the simplest method of attaching and removing pads. An additional option I considered was using metal strips and magnets, but I was unsure whether the magnetic force would survive the scrubbing mechanism, and decided to go for velcro as the simpler option. I then, using the 7 inch diameter of my robot and the average length of a commmand strip as constraints, drew out my scrubbing mechanism. I decided on a 2.5 inch diameter wheel spinning, as this would allow for 5 inches of linear coverage, according to l = 2r, a governing equation for crank and slider mechanisms. 

Finally, I have decided to use a stepper motor to run the scrubbing mechanism. I initially considered a servo motor, but quickly realized that, for Phase 2 of this project, I will need to precisely move the cleaning pad mount to a certain spot to allow for consistent changing of pads. Thus, I decided to use a stepper motor as that will provide me greater precision that a servo. 

**Decisions**: Velcro linkages between pads and mount, 2.5 inch diameter wheel for crank and slider mechanism, and swapping servo motor with stepper motor

Further Questions:
- how will I link the pieces in my project together? screws? custom 3d printed joinings? 
- In my initial sketches, I assumed one velcro piece would be enough. Will this hold to be true? 

## Components Update -- 5/29/26
This is multiple design decisions rolled into one, so I will try an dedicate a few paragraphs, one for each decisions. First,  I decided on the G12 N20 DC motors to drive my robot. Upon research, I discovered that N20 motors are a classic choice for robots, so I decided to use them as a useful starting point for this project. I decided on the G12 N20 motors because this was the type that I found the most documentation for, which is useful when deciding power current requirements. 

I also decided to use the L293D motor driver and the ULN2003 Stepper Motor Driver for my DC and stepper motors respectively. The primary rationale for this decision is that they came with the ELEGOO kit that I ordered and are useful for prototyping. If needed, I will order a different motor driver. It is worth mentioning that, according to my calculations, the L293D driver does not provide enough current for my motors IF both of them stall. Ideally, I would design my system to avoid my motors stalling, but I will note this here and will likely replace the L293D as I move out of prototyping. Additionally, I have decided to use the power supply module given with the ELEGOO kit to regulate power for now. 

Finally, the battery. I first researched and noted the documented voltage and max current values for components that would need to connect to the battery. These values can be found in docs/commponents. By summing the max current values for the stepper motor, both DC motors, and the ESP 32 board, I arrive at 2080 mAh. Because I would like the robot to run for 30 minutes on one charge, I decided on a 1040 mA minimum current requirement. I then applied a 20% buffer (1040/0.8) to bring that number up to 1300 mAh. To be safe, I decided that 1500 mAh should be good for the battery. The DC motors require the largest voltage at 6V, and the VIN pin on the ESP32 is only able to handle up to 12V. To be safe, I decided to go for between the 5-8V range, which should be more than safe for the ESP32. Therefore, I decided to use a 7.4V Lipo Battery. This was one of the cheaper batteries I saw, yet simultaneouly met all of my requirements. 

These decisions ultimately provide a natural power architecture. The battery will connect to three components: The ESP32 VIN, which handles up to 12V, the L293D motor driver, and the power supply module. The power supply module will then power the stepper motor and its driver, both of which require 5V. 

**Decisions:** G12 N20 Motors for driving robot motion, L293D motor driver and the ULN2003 Stepper Motor Driver for DC and stepper motors respectively, power supply module from kit for voltage regulation. 7.4V Lipo Battery with 1500 mAh. Power Architecture has been decided. 

Further Questions:
 - What size wheels will I need for robot.
 - How many IR sensors do I truly need?
 - what is the true ESP32 current draw? My current number is a rough estimate. 

## IR Line Sensors Quantity and Placement + Robot Driving Pattern -- 5/29/26
In order to decide how many IR sensors I needed I first need to decide how my robot is going to move. I quickly decided on a lawnmower style pattern, with only forward motion and pivoting. This is the simplest way I could think of to code the robots motion, and will make planning this project much easier. Therefore, I have decided on 2 IR sensors, one in the very front and one in the very back. When the Robot is moving forward, we will obviously need a sensor in the front to detect when the robot is off the edge. When pivoting, however, the front and back of the robot will travel in a arc around the wheel that has been designated the pivot. Obviously, whatever wheel is pivot will depend on the direction turning, but this means that the front or back will likely move off the desk if close to the edge of the desk. Having these two sensors here will prevent that from happening. 

**Decision:** Lawn Mower Traversal pattern and 2 IR sensors in the front and back for edge detection. 

## Wheel Diameter size  -- 5/31
After sketching a quick dimensioned paper sketch (visible in docs/sketches folder), I have decided on 3 inch wheels for the drive train of this robot. This decision was made primarly due to an estimated thickness of a swiffer dusting pad. Unfortunately, I do not have access to the actual swiffer pads for the moment, but online estimates ranged from 1.5-2" when fully fluffed. To get the effectiveness of the pad, it will need to be compressed. Thus, I decided to allocate roughly 1" of space below the robot for the pad itself, with 0.5" for the mount to hold the pad.

With 1.5" of space below the robot, I naturally concluded that I needed 3" diameter wheels. I had already planned on keeping the motor housing for the wheels inside the chassis, which would mean that the middle of the wheel would have to be in the chassis, in line with the motor axle. This mean I would need a 1.5" radius wheel to keep the robot 1.5" off the robot. Additionally, I have only ordered 2 wheels for now. I will test using the scrubbing mechanism itself as a third point of support: if this is too unrealiable, I will research and decide to implement a caster wheel.

**Decision:** 3" wheels will be used in drive train system. Will consider caster wheel after first prototype. 

Further Questions: N/A

## Wheel Diameter resize + Dust Pad change  -- 6/23
I've been on vacation for a while, so work on this project has slowed, and I have gotten lax at updating this repo. I've been working on the robot chassis design in my free time, and have since recognized that I simply cannot fit everything in as it stands with 3 inch wheels. With the battery I have chosen and the restraint of a 7 inch diameter, there simply isn't enough space to fit everything in as it stands. Thus, I've decided on downsizing to 2 inch wheels, which will give me roughly 1 inch of ground clearance. I feel comfortable with this due to a recent discovery I have made: swiffer dusting pads. Previously, I was working under the assumption that I would be using large, handheld fluffy dusting pads for my robot. I have since visited target and discovered that swiffer actually makes thinner, dusting pads intended to be put on a mop. With these, I can assume the pad has negligable thickness and not be concerned with fitting a thick pad under my robot. 

**Decision:** 2 inch wheels will be used in the drive train system, and I will be switching to thinner swiffer dusting pads. 

Further Questions:
 - How will I acquire these new wheels? 3D print or buy new ones?
 - How will I keep track of the distance that the robot moves? Math or a device?
 - For this robot to work, I will need both the ultrasonic sensor and the IR line tracker in the front of the robot. How will I reconcile the fact that both these devices need to take up a similar about of space?

 ## Wheel acquisition -- 6/25
 After some thinking, I have decided to buy wheels online. This is a bit unfortunate because I already bought some 3 inch wheels that are now useless, but I digress. After researching online, I have discovered that the tolerances to make these wheels fit into the the motor are very finnicy for a 3D printer, and that the DC motor I have chosen, G12-N20, already has wheels that you can buy for cheap on amazon. Thus, I am deciding to buy one of these wheels, which I will order soon. Now this does come with a drawback, which is that the only wheels that I can find are 43 mm wheels, which is roughly 1.7 inches. This is slightly smaller than the wheels that I originally wanted, the 2 inch wheels. This will leave me even less ground clearance than I originally intended. I have decided that to work with this, and attempted to make my cleaning mechanism fit in the roughly 0.85 inches of ground clearance I know have. 

 **Decision:** I will purchase my wheels for the drive train. This will shrink my ground clearance, which I have decided to work with. 

 Further Questions:
 - How should I opt to fit in my cleaning mechanism under the robot now that my space has shrunk. 
 - How will I make the cleaning pads replacable? 
 - How should I think about mounting my step motor to the chassis to drive the cleaning mechanism. 

 ## Cleaning Pad -- 7/4
 Because I have now switched to the thinner dusting pads used on maps, I now have a greater degree of flexibility in deciding the length of the cleaning pad itself. I have decided on a 4x2 inch cleaning pad dimensions, which I will note in my components list. I arrived at this number largely as a reasonable guess to what would a good length be. 8 inches of surface area to clean should certainly be a big enough number for a countertop/desk while still being small for the robot, and this will also make it (roughly) the size of my velcro strips. This makes it so that there is little overhang from my cleaning pad over my velcro strip, which I believe is preferable. This dimension is very much subject to change as I begin to run the numbers and decide if the mechanism I want to fit is possible. 

 **Decision:** Cleaning pad length will (temporarily) be 4x2 in. 
 **Next Steps:** Based on this length, redo all of the math and redesign the cleaning mechanism with the chassis and this new constraint in mind. 

 ## Cleaning Mechanism significant redesign -- 7/4
 I have had a significant realization while working on measuring out this cleaning mechanism. I kept running into the issue where I was struggling to balance the amount of space I had. with the constraint of the 6.5" chord, I simply could not figure out a way to balance the lengths. This was especially hard due to my realization that, since I am elevating the motor shaft above the floor of the chassis, the length of the slider is NOT simply 2 times the radius, but a little more than that, which would involve a lot of decently complex math to do so, as it introduces an angle of elevation since the crank arm is not perfectly inline with the slider. By using a linkeage system and having the crank and the slider side by side, I simply would have to make the slider so small that the cleaning pad would be hardly oscillating, which to me, defeats the whole purpose of having an oscillating cleaning pad in the first place. 

 This resulted in me researching other ways for me to convert rotational motion into linear motion. I have since arrived at the scotch yoke mechanism. With this mechanism, the crank arm is able to sit perpindicular to the slider, which means that I can place my stepper motor above or below the slit in the floor, where I have signficantly more space than I do right now. This will greatly simplify my design. Best of all, the mechanism uses a simple L = 2r for the slider length, and does not require the complex math that the linkeage system does. 

 **Decision:** Shift from a linkeage system to a scotch yoke system for my cleaning mechanism. 
 **Further Questions/Steps:** From here, I need to start sketch what this system will look like and dimension it on paper. From there, I can CAD the model and have it ready to be added to the main chassis assembly. 

 ## Step Motor Mount -- 7/6
 I have just finished designing my Step Motor Mount, which can be found for the time being in hardware/chassis. For the future, I might add a mounts folder in hardware due to the fact that I have design multiple mounts throughout the project. Design for this mount was pretty straight forward, although the main decision here comes at the walls of the mount. The way I have it, the walls are very thin towards side holes for the motor. I worry about structural integrity of the mount with such thin walls, but I have for the time being decided to keep this as the first version and design a different mount later. 

 **Decision:** Use current iteration with thin walls for the Step Motor Mount, and decide in the future whether the mount needs redesigning. 

 ## Cleaning Mechanism decisions -- 7/6
 Two decisions to report here after doing CAD on the new cleaning mechanism. The first is relating to the "crank arm" of the mechanism. I have decided to use a circle attached to the motor shaft for this project, because I deemed it simpler to design while getting full functionality. I worried particularly about accidentally designing an arm too small and thing that would snap, and with a circle, the chances of that happening dwindle significantly. On a practical note, using a circle made it easier to see the amount of space the mechanism would be taking place, rather than a single arm where I would have to visualize its path through one shaft rotation. Additionally, I have decided on a crank radius of 1 inch, for roughly 2 inches of travel. 

 The second relates to the crank pin. I initially considered designing and 3D printing a dowel that would fit into the circle, and thus be used to shift the cleaning pad as the wheel turned. I worry, however, that the plastic on plastic friction will degrade the dowel, and make the mechanism fail over time. I have thus decided to use a a steel rod as a dowel, that I will cut to length. Plastic on metal should result in a much smoother glide, and importantly, should not seriously degrade the plastic over time. 

 **Decisions:** 2 inch Circle with steel rod pin for the crank arm. 

 **Further Question:** What size steel rod should I use for the pin, and will choosing to do this increase my costs severely? 

## Cleaning Mechanism Decisions  -- 7/7 
Today, I have finished my second version of the cleaning mechanism, which is very exciting. One of the decisions I arrived at today was deciding the size of the steel dowel I will use. For simplicity, I will 3mm dowel, as I found multiple 3mm steel rods for relatively cheap on Amazon. 

Additionally, I must begin to consider the actual attachment of the cleaning pad. For this, I was considering designing a piece that will hold a velcro strip that the cleaning pad will attach to, and then towards the top of that piece, a place to put an adhesive magnet. The main reason I want to use magnets to attach the final piece holding cleaning pad is ease of transfer. By using a magnet, replacing the cleaning pad becomes as easy as peeling off the final piece, rather than unscrewing a part of flipping the whole robot over. Even better, I know observationally that it is decently difficult to slide two magnets off of each other, but relatively easy to peel them off. This means that the piece should not slide off during the lateral motion of cleaning. 

**Decision:** 3mm steel dowel for crank pin, and using magnets to attach the piece holding the cleaning pad for the cleaning mechanism. 

**Further Steps:** Begin deciding on electrical component placement, design the last mounts, and research the materials necessary for a sanitizing pump. 

## Project Scope Redefining -- 7/7
As I continue to work through this project, I begin to realize that the scope of this project is vast, far vaster than I originally intended. And while I think much of the complexity of this robot is good, I do believe that a certain aspect of the project is needlessly complicated: the stage two pad swap. 

Originally, I determined the need for a two phase system based on the fear of smearing. Basically, that if I straight away sprayed a sanitizing solution and scrubbed back and forth, the debris and dirt would simply smear on the surface rather than be properly collected. I have since decided that this is no longer a worry. A desktop is many scales smaller than a floor: I'm betting that the volume of debris is proportionally scaled down as well, enough to where smearing is a nominal issue.

This also helps my project timeline, as it reduces the number of subsystems I need to design, and focuses in on the core of the project: an autonomous desktop vehicle that fully traverses a desktop/countertop. I am therefore redifining the project as follows:

The project is a desktop sweeper and sanitizer, that travels the area of the desk and simultaneously sweeps and sanitizes it using a scrubbing cleaning pad and sanitizing spray. Phase one of the project involves creating the robot with the cleaning mechanism and spray, and being able to control the robot through bluetooth commands. Phase 2 of the robots will involve making the robot fully clean any square or rectangular surface autonomously. I hope for this redefinition to realign my goals and better narrow the scope of this project. 

**Decision:** Eliminate the prior phase 2 pad swapping, and focus purely on making an autonomous robot that sweeps and sanitizes the surface in one pass. 

**Further Questions:** Is my bet right, or will smearing occur with only one pass through?

## Sanitizer Decisions -- 7/9

**DECISION ONE: SETUP TYPE**

Now that I have finished my first design of the cleaning mechanism and am ready for testing the physical model of it, I have turned my attention to the santizing system. I first researched the different types of pumps used and found two main setups for hobby projects like mine: a submersible DC pump, or a external peristaltic pump. I have chosen to use the submerisble DC pump, for a few reasons. Because this is my first project that I am attempting, I am foing my best when possible to choose the simpler option, and the DC pump, according to my own research, is the simpler choice to implement. Additionally, I found that it is cheaper to set up and more space efficient, since it combines the pump and liquid resevoir together. 

**Decision:** Submersible DC pump will be used to drive sanitizing mechanism

**DECISION TWO: RESEVOIR SIZE AND TYPE**

Now that I have decided the pump set up, I now bring my attention to the resevoir. From my own research, I estimated that the average spray nozzle releases roughly 1 ml of liquid per squirt on the medium range. From my 5/29 decision, I have decided on a lawn mower style traversal pattern, and I am envisioning no more than 2 squrts per forward traversal of my robot. If we imagine that the typical desk requires at most 5 forward traversals from start to finish, then we are looking at a maximum of 20 spurts, or 20 ml of liquid. I would like one refill to allow for 5 cleans, so we are looking at a rough estimate of 100 ml of liquid. This will serve as my starting point for the project, and I will change this number if needed. Additionally, because I would like the resevoir to be easily refillable and conform to the limited space I have in my chassis, I have decided to design my own resevoir. 

This comes with issues: won't the presence of liquid risk mold growth in my 3D print, especially if I am using PLA? For the time being, I have decided to mitigate this by committing to a very strong chemical cleaning spray that is naturally anti microbial growth to mitigate this. I will redesign if it soon becomes clear that the resevoir is building up mold. 

**Decision:** A custom designed, 3D printed resevoir with 100ml capacity will be used, with 100ml subject to change later

**DECISION THREE: NOZZLE TYPE**

Finally, I have elected to go with a fan nozzle for maximum coverage. I want the entirety of the cleaning pad to have some of the liquid on it to make sure no gaps are made in cleaning, so I would like to cover most of the 6.5 in chord (maybe 4-5 in of it, give or take), and a fan nozzle will grant me that coverage. To decide on the angle, I will order a few different angles and pick the one I like the most

**Decision:** Fan nozzle to be used for maximum coverage of surface area. Ordering multiple (2-3) angles to decide on the best one. 

**Further Questions:** 
 - How will the introduction of the resevoir change my weight distribution?
 - How shall I plan my space so everything manages to fit into my chassis?
 - Which nozzle size will end up being the right size for me?
 
 ## Components Wiring Diagram -- 7/22
 I have drawn an initial components wiring diagram, which can be found in /docs/sketches. Keeping with my 5/29 decision, I am keeping three things plugged into the battery's positive terminal. The diagram includes components such as the Ultrasonic sensor, L293D, two DC motors, and the stepper motor driver and stepper motor, and the IR sensor. I haven't yet figured out the exact setup of the sanitizer, so I will leave that up in the air. 

 This is a really straightforward design decision, but I think the steps that come with this are more interesting. I will be using wokwi to plan out with GPIO pins of the ESP32, and start trying the preliminary code to try and see if it will work. Additionally, I will be getting a Caliper tomorrow, which I will use to finish blocking out the 3D model to make sure I have enough space in the current model to fit all my components. 

 No further questions. 

 ## Switch from Power Supply Module -- 7/24
 I have decided to switch away from the power supply module for my project, and instead switch to a cheap voltage regulator that drops the voltage down to 5V. I have done this for two reasons. The first is that the power supply module is made for breadboards, and I want this project to be on PCB, for permanentability and to learn soldering, so soldering this power supply to a PCB is very difficult. The second reason is that the power supply module is very large, coming in at over 2 inches long. This is a lot of space, which is a very limited resource for me since I have decided to (mostly, I expanded some parts of the chassis) stick to the 7 inch diameter chassis. Thus, it simply makes sense for me to switch to a voltage regulator, which is much smaller, as both its length and width are under one inch. 

 **Decision:** Switch from power supply module to voltage regulator

 **Further Questions:**
  - Where should I place the voltage regulator to optimize space?
  - Where should I place ALL components to make efficient use of my space?

  ## Reprinting parts - 7/30
  I have printed the first parts for the robot. I have decided to reprint the sliding arm for the cleaning mechanism, as it was extremely delicate after the first print and snapped. I have doubled the thickness, so hopefully this will last better. Additionally, after some intial testing, I realized there wasn't enough holding the sliding arm into place to truly translate into linear motion. I have redesign the conecting piece to include some support from the bottom of the chassis to ensure that the sliding arm is only moving linearly, and not shifting diagonally 

  **Decision:** Reprinting components of cleaning mechanism to improve functionality of said mechanism 

  ## PCB and component mounting 8/4
  I have started truly soldering, which has been great. One thing I did not anticipate is have a bunch of wires below my PCB for wiring components to my ESP32. Thus, I have decided to design some mounts that would elevate my PCB above the chassis floor, which will allow some space for the wires to flow. This doubles as a space saving mechanism, as this clears up some space on the chassis floor (now below my PCB) for my motors, which previously did not have the space to place. I will spend the rest of this week trying to wire and get as many components on the chassis as possible, and will begin thinking about the sanitizing and code next week. 
  **Decision:** Designing mounts for the PCB to elevate above the chassis floor, and designing mounts for other electrical components, such as the stepper motor driver and the voltage regulator

## Restarting wiring process - 8/8
Today, after having soldered my motors and ESP32 to a PCB, I tried to connect my ESP32 to my laptop and failed. This resulted in one, horrifying conclusion: I somehow managed to ruin the usb connection point on my ESP32, thus resulting in windows devices not recognizing the chip. This cannot be proven, but after 3 hours of constant debugging and testing, it is the only conclusion that I can come to, as no solution worked for this. I have thus come to the only solution that I can: restarting. I have ordered a new ESP32 chip, and will spend next week soldering components together to try and complete this project. This is obviously a huge set back in my project, both time and cost-wise. 

This has been a big blow to my morale, but I am going to try my hardest to not let this affect me. While I am waiting for my new board, I have decided to begin development on my firmware. I am planning on using the ESP32 to create a web server where I can send commands from my laptop to the board. This way, I can autonomously command the robot to begin cleaning in the future. I will begin development on both this and basic movement options while I wait for the new components to arrive. 

Because of this set back, I am also quickly running out of time before school starts. Therefore, I have decided to focus on solely a drivable robot that can sweep items. For the time, I will make the sanitizing part of this robot a phase 2 problem, and make phase involve a drivable, sweeping robot. If I move faster than I expect on my schedule, I will adjust accordingly. 

Finally, although this was kind of a downer of a design decision, this does give me the chance to greatly improve upon on how I think about soldering and PCB. For starters, in order to avoid messing up my boards like I did this time, I will be using IC sockets on my PCB, rather than soldering components directly to my PCB. This should avoid connection issues like what happened with this time. Secondly, in my previous design, I left all wire connections beneath the board. This was a grave mistake. It led to a jumbled mess of wires below the board, and made it impossible to even conceive mounting my PCB to the chassis. I will be leaving all my wiring above the board this time. 

**Decision:** Redoing all soldering due to non responsive ESP32. Will iterate, using IC sockets to avoid direct soldering of components, and a more structured approach to wiring, making PCB mounting easy. Will begin to early work on firmware code to speed up process, and moved sanitizing spray to phase 2 to ensure phase 1 completion before summer's end.

**Further Questions:** 
 - What pins am I going to assign to what components?
 - Even though it is phase 2, it is worth planning out how I am going to make this robot autonomous now for easy transitions
 - will I need to reprint the chassis to fit in necessary components?
 - The ultrasonic sensor sends out 5V signals through its echo pin. Will I need to use resistors to step this down for the ESP32's 3.3V pins? How will this work?

 ## Header File Organization + RME Convention -- 8/9

 I began writing .hpp files for controlling my motors and sensors. For these header files, I have decided to document using definied Abstract Functions, Representation Invariants, and definied RMEs **when necessary.** Crucially, I did not want to spend a ridiculous amount of time documenting when that time could be spent coding, so I have decided to always specify an AF and Rep Invariant, whether or not they exist. For general methods, I will either use a comment line describing the method or an RME, depending on what the methods functionality is. I suspect that RME's will not be required until I begin designing my autonomous navigation. 

 **Decision:** Adopt AF and Rep invaraint documentation (or lack therof) in my code, and RME when I feel appropriate

 ## Motor and Sensor Data Representation -- 8/9 
 
 When I was designing on my header files, I came up with two distinct data representations for each case. For the motors, I decided to use an enum class to represent the driving state of the robot, and set up a rep invariant that the current state of the robot must match one of the listed driving states in the enum class. This has a few advantages: there truly are only a select number of states that the robot can drive in, so this helps eliminate undefined robot behavior. Addtionally, this lets me set specific requirements for each state, or perhaphs in between states (like not turning too fast after driving straight or backwards). 

 For the Sensors, I was more conflicted. I considered using a state representation like I did for the motor, where I would continuously store and update the state of each sensor. This would be helpful for autonomous driving, but is a little more complicated to design currently. Therefore, I have decided to simply create a set of boolean functions that translates the sensor data into actioanable items (does floor exist? or is object in front too close?). This simplifies matters for now, which is why I have tentatively decided on this structure. However, this may need to change in the future as I design autonomous travel. 

 **Decision:** State based representation for motor control, and (tentatively) statless representation for sensors, where information is not stored in a vairable, only updated through boolean methods

 **Further Questions:**
  - Should front and back floor sensors have multiple public methods, or just one public method?
  - is there ever a scenario where the front and back IR sensors will both read that the floor does 
    not exist?

## Pinout Assignment -- 8/10
I have decided on and assigned pins of the ESP32 to be wired to the various motor drivers and sensors. The list is as follows: 
 - L293D
    - 25, 26 --> Left Motor Input pins
    - 32 --> Left Motor Speed Control
    - 27, 14 --> Right Motor Input pins
    - 33 --> Right Motor Speed Control
  - Ultrasonic Sensor
    - 18 --> Trig Pin
    - 19 --> Echo Pin
  - IR Sensor
    - 16 --> front IR sensor digital pin
    - 17 --> back IR sensor digital pin
  - Stepper Motor 
    - 4, 13, 21, 23, --> IN1, 2, 3, and 4 respectively. 

These pins were chosen in accordance with an ESP32 pinout I saw, and I tried to choose the safest pins I saw for the task at hand. 

**Decision:** ESP32 pins assigned as above

**Further Questions:**
  - Will I have enough ESP32 pins to wire another L293D for the submersible motor for the spraying mechanism in Phase 2









