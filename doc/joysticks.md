Game Controllers
================
Linux handles game controllers via the joystick driver, mounting them to `/dev/input/js*`.
From there, button and joystick state are easily readable using standard Linux libraries.
To see an example of this, see the [joyutils](https://github.com/RoboticsatUCD/MateROV/tree/master/test/joystick-1.2.15) code.

Using joyutils, one can test a game controller on kymi either with `jstest`, or `jstest-gtk` if graphical output is preferred.
