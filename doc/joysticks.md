Game Controllers
================
Linux handles game controllers via the joystick driver, mounting them to `/dev/input/js*`.
From there, button and joystick state are easily readable using standard Linux libraries.
To see an example of this, see the [joyutils](https://github.com/RoboticsatUCD/MateROV/tree/master/test/joystick-1.2.15) code.

Using joyutils, one can test a game controller on kymi either with `jstest`, or `jstest-gtk` if graphical output is preferred.

XBox 360 Controller Axis and Button Mapping
===========================================
The joystick driver mapping for the XBox 360 game controller is as follows:

	Left JS:          Axes 0 and 1
	Left Trigger:     Axis 2
	Right JS:         Axes 3 and 4
	Right Trigger:    Button 5
	Directional Pad:  Axes 6 and 7
	A Button:         Button 0
	B Button:         Button 1
	X Button:         Button 2
	Y Button:         Button 3
	Left Bumper:      Button 4
	Right Bumper:     Button 5
	Back Button:      Button 6
	Start Button:     Button 7
	XBox Button:      Button 8
	Left click:       Button 9
	Right click:      Button 10

The joysticks are nominally centered at (0, 0) but have wide margins of approximately ±2000, with what may either be susceptibility to chassis noise or cross talk with other control inputs.
Perhaps calibration is required to fix this, or will software compensation be required?
The directional pad's rest position corresponds to zero while the, triggers' rest position corresponds to full negative.
