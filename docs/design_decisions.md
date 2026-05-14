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




