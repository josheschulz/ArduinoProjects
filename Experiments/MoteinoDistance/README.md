Discovering Distance With Moteino's
===================================

I wanted to know if I could use RSSI from a motino as a proxy for distance.

I wrote these programs to gather the data.  The Gateway was plugged into my laptop
sitting at a fixed point.  Another Moteino was on a breadboard with a 9V battery.  At
each step my assistants (my daughters) would press the button and increment the run number. 
That was how we could tell how far away each series was. 

Each step was 2.5 yards (because that's the only tape measure we could find).

There were problems with collection: At one point a neighbor came home and they had to move.  The
tape measure wasn't very accurate and my youngest daughter (holding the remote) had a tendency to 
wander around while my other daughter was measuring.

Tl;Dr: The data is dirty.

But you can clearly see a pattern, and with enough samples I think it will be usable.

We did another set where we put the moteino in the bike basket and then rode back and forth for about 20 yards.

You can clearly tell, looking at the graph where we were at each point.

We did three runs:  Zoe by herself, Zoe and Kyra, Then all three of us.

It's hard to tell for sure because we went different speeds, but it is clear that with the three of
us riding there are more very bad samples.  We may want to throw out anything under a certain floor.

I wish there were more tour de fats so I could play around with it.

Data is in GateWayData
https://github.com/josheschulz/ArduinoProjects/blob/master/Experiments/MoteinoDistance/Gateway/data/

The pictures are: https://github.com/josheschulz/ArduinoProjects/blob/master/Experiments/MoteinoDistance/Gateway/data/Average_over_distance.png
and: https://github.com/josheschulz/ArduinoProjects/blob/master/Experiments/MoteinoDistance/Gateway/data/Average_over_distance.png
