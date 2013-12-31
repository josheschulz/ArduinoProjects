Color Changing With Buttons
===========================

This loops through and changes the color of the tri-LED based on buttons you push.

One button is wired to the 0 interrupt (pin 2), and two buttons are wired to pins 10 and 11.

The two buttons are used to determine which color to increment.  If no buttons are pressed
then the red value is incremented.  If the button on pin 10 is held down while you press the
interrupt button then the Green value is incremented.  If the button on pin 11 is held down while
you press the interrupt button then the Blue Value is incremented. 

If both buttons are held down everything resets.

Regardless, nothing happens unless you hit the interrupt button.

After I was done I found this: http://learn.adafruit.com/adafruit-arduino-lesson-7-make-an-rgb-led-fader/arduino-code

Which is the same idea but a little simpler.  

Note to Self
============

Serial Communication is wonky in interrupts.  If you use the logging library it will work, occasionally
but it will also occasionly stop doing anything  This is painful to debug. 

Be careful using serial communications in interrupts.  Need to figure out a better way to do that.

Perhaps enqueue a string into an array and dump them out to the logger in the main loop?  That's
an idea worth chasing.
