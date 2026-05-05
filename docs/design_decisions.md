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

## 5/5 Chassis Diameter
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
