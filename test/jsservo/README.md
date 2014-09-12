jsservo: Proof-of-Concept Commander and Event Handler
=====================================================
This code implements a simple two-axis servo controller on Arduino.
The Arduino is an event handler for serial communication from a PC, which runs the commander program.

This source tree was created using [ino](http://inotool.org/).

servohandler/src/servohandler.ino
---------------------------------
This code handles the servo interface and interprets the commands from the PC.
It can be simply built and uploaded to the Arduino.
It expects the servo outputs on Analog pins 0 and 1.

jscommander.c
-------------
This is code adapted from Vojtech Pavlik's [joyutils](https://github.com/RoboticsatUCD/MateROV/tree/master/test/joystick-2.2.15) program jstest.
Its one required argument is the joystick device file, normally located in `/dev/input/`.
It simply outputs commands on `stdout` based on a linear map of the left joystick's two axes.
Simply use gcc to compile on any Linux system.

Known issue: Transmission saturates after a few seconds and the control is disconnected.
I'm not sure why this occurs.

jscommander2.c
--------------
This is version of jscommander that uses the serial library to directly write to the serial device rather than requiring the user to configure it and handle the piping in the shell.

This implementation does not have the transmission saturation problem as the other does, probably because of the more strict setup of the serial device capabilities in the serial library.
However, the main switch condition that populates the state arrays for the joystick device needed to be changed to ignore `JS_EVENT_INIT`.
Otherwise, the when the automatic starting series of the joystick ends and input halts before analog mode is engaged, the program crashes on a malloc() error:

	jscommander2: malloc.c:2369: sysmalloc: Assertion `(old_top == (((mbinptr) (((char *) &((av)->bins[((1) - 1) * 2])) - __builtin_offsetof (struct malloc_chunk, fd)))) && old_size == 0) || ((unsigned long) (old_size) >= (unsigned long)((((__builtin_offsetof (struct malloc_chunk, fd_nextsize))+((2 *(sizeof(size_t))) - 1)) & ~((2 *(sizeof(size_t))) - 1))) && ((old_top)->size & 0x1) && ((unsigned long) old_end & pagemask) == 0)' failed.
	Aborted

Now, there are two `Resource temporarily unavailable messages` that accompany a serial write error, but the code works fine.
The code writes all commands to the dumpfile `dump` in binary mode, but no output is seen during the pause.

src/connect.sh
--------------
This file lays out the commands necessary to successfully control the servos once the handler is uploaded to the Arduino.
Specifically, it is necessary to set up the Arduino teletypewriter device with the right baud rate and parity, etc.
The second two commands show how to achieve input and output from the handler, respectively.
They assume your device file names are the same as mine.
