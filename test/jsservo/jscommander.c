/*
 * Joystick interface and commander.
 *
 * Copyright 2014, Egan McComb
 *
 * This code was adapted from GPL licensed:
 *
 * > jstest.c  Version 1.2
 *
 * > Copyright (c) 1996-1999 Vojtech Pavlik
 *
 * > Sponsored by SuSE
 */

#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <linux/joystick.h>

#define NAME_LENGTH 128

int main (int argc, char **argv)
{
	int fd;
	unsigned char axes = 2;
	unsigned char buttons = 2;
	int version = 0x000800;
	char name[NAME_LENGTH] = "Unknown";

	if (argc != 2 || !strcmp("--help", argv[1])) {
		puts("Usage: jscommander <device>");
		exit(1);
	}
	if ((fd = open(argv[argc - 1], O_RDONLY)) < 0) {
		perror("jscommander: Unable to read file descriptor");
		exit(1);
	}

	ioctl(fd, JSIOCGVERSION, &version);
	ioctl(fd, JSIOCGAXES, &axes);
	ioctl(fd, JSIOCGBUTTONS, &buttons);
	ioctl(fd, JSIOCGNAME(NAME_LENGTH), name);

	printf("Joystick (%s) has %d axes and %d buttons. Driver version is %d.%d.%d.\n",
		name, axes, buttons, version >> 16, (version >> 8) & 0xff, version & 0xff);
	printf("Running... (SIGINT to exit)\n");

	/*
	 * Event interface.
	 *
	 * For PS2 controller via usb adapter:
	 * 		Left JS:     Axes 0 and 1
	 * 		Left click:  Button 10
	 * 		Right JS:    Axes 2 and 3
	 * 		Right click: Button 11
	 * 		D Pad:       Axes 4 and 5
	 * 		Select:      Button 8
	 * 		Start:       Button 9
	 * 		Left 1:      Button 6
	 * 		Left 2:      Button 4
	 * 		Right 1:     Button 7
	 * 		Right 2:     Button 5
	 * 		Triangle:    Button 0
	 * 		Circle:      Button 1
	 * 		Cross:       Button 2
	 * 		Box:         Button 3
	 */
	int *axis;
	int *button;
	int i;
	struct js_event js;

	axis = calloc(axes, sizeof(int));
	button = calloc(buttons, sizeof(char));

	while (1) {
		if (read(fd, &js, sizeof(struct js_event)) != sizeof(struct js_event)) {
			perror("\njscommander: Error reading device");
			exit (1);
		}

		switch(js.type & ~JS_EVENT_INIT) {
		case JS_EVENT_BUTTON:
			button[js.number] = js.value;
			break;
		case JS_EVENT_AXIS:
			axis[js.number] = js.value;
			break;
		}

		printf("\r");

		/* Use axes 0 and 1 to control servos. */
		if (axes) {
			printf("%dx%dy", axis[0]/364+90, axis[1]/364+90);
		}

		//if (buttons) {
		//	printf("Buttons: ");
		//	for (i = 0; i < buttons; i++)
		//		printf("%2d:%s ", i, button[i] ? "on " : "off");
		//}

		fflush(stdout);
	}
}

// vim: tabstop=4
