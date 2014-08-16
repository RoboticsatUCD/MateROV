jsservo: Proof-of-Concept Commander and Event Handler
=====================================================
This code implements a simple two-axis servo controller on Arduino.
The Arduino is an event handler for serial communication from a PC, which runs the commander program.

This source tree was created using [ino](http://inotool.org/).

src/servohandler.ino
--------------------
This code handles the servo interface and interprets the commands from the PC.
It can be simply built and uploaded to the Arduino.
It expects the servo outputs on Analog pins 0 and 1.

src/jscommander.c
-----------------
This is code adapted from Vojtech Pavlik's [joyutils](http://atrey.karlin.mff.cuni.cz/~vojtech/joystick/), which is included in the tree.
Its one required argument is the joystick device file, normally located in `/dev/input`.
It simply outputs commands on `stdout` based on a linear map of the left joystick's two axes.
Simply use gcc to compile on any Linux system.

src/connect.sh
--------------
This file lays out the commands necessary to successfully control the servos once the handler is uploaded to the Arduino.
Specifically, it is necessary to set up the Arduino teletypewriter device with the right baud rate and parity, etc.
The second two commands show how to achieve input and output from the handler, respectively.
They assume your device file names are the same as mine.

src/joystick-1.2.15/
--------------------
Vojtech Pavlik's joyutils software serves as a good reference on how to write joystick drivers.
