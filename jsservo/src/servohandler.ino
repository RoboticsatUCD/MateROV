/*
 * Command handler and servo interface.
 *
 * Command syntax is numeric ASCII payload for position in degrees,
 * followed by ASCII characters 'x' or 'y' to select the appropriate
 * servo.
 */

#include <Servo.h>

/* Treat the servos as two axis actuator. */
Servo xservo;
Servo yservo;

/* Set the default positions. */
int xpos = 0;
int ypos = 0;

void setup()
{
	/* Select which analog pins we will be using. */
	xservo.attach(14);				// Analog Pin0.
	yservo.attach(15);				// Analog Pin1.

	/* Setup communication. */
	Serial.begin(19200);			// A high baud rate.
	Serial.println("I'm here!");
}

void loop()
{
	static int v = 0;
	if (Serial.available()) {
		char ch = Serial.read();

		/* Command handler. */
		switch (ch) {
			case '0' ... '9':			// Numeric payload string.
				v = v*10 + ch - '0';	// Convert to integer.
				break;
			case 'x':					// Servo selection: x.
				xservo.write(v);
				v = 0;
				break;
			case 'y':					// Servo selection: y.
				yservo.write(v);
				v = 0;
				break;
			default:
				Serial.println("Unknown command received!");
				break;
		}
	}
}

// vim: tabstop=4
