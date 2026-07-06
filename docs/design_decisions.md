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




