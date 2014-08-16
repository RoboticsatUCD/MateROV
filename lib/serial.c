/*
 * Simple library for reading/writing Arduino serial device.
 *
 * This code was adapted from MIT licensed:
 *
 * > arduino-serial-lib
 * > 2006-2013, Tod E. Kurt, http://todbot.com/blog/
 */

#include "serial.h"

#include <stdio.h>     // Standard input/output definitions.
#include <unistd.h>    // UNIX standard function definitions.
#include <fcntl.h>     // File control definitions.
#include <errno.h>     // Error number definitions.
#include <termios.h>   // POSIX terminal control definitions.
#include <string.h>    // String function definitions.
#include <sys/ioctl.h> // I/O control definitions.

/* Uncomment this to debug reads. */
//#define SERIALPORTDEBUG

/*
 * This function takes the string name of a serial device and a baud
 * rate in bps and connects to that device at that speed and 8N1 in
 * fully raw mode so binary data can be sent.
 *
 * It returns a valid file descriptor, or -1 on error.
 */
int serialport_init(const char* serialport, int baud)
{
	struct termios toptions;
	int fd;

	//fd = open(serialport, O_RDWR | O_NOCTTY | O_NDELAY);
	fd = open(serialport, O_RDWR | O_NONBLOCK);

	if (fd == -1) {
		perror("serialport_init: Unable to open port ");
		return -1;
	}

	//int iflags = TIOCM_DTR;
	//ioctl(fd, TIOCMBIS, &iflags); // Turn on DTR.
	//ioctl(fd, TIOCMBIC, &iflags); // Turn off DTR.

	if (tcgetattr(fd, &toptions) < 0) {
		perror("serialport_init: Couldn't get term attributes");
		return -1;
	}
	speed_t brate = baud; // Can override switch if needed.
	switch(baud) {
		case 4800:
			brate=B4800;
			break;
		case 9600:
			brate=B9600;
			break;
#ifdef B14400
		case 14400:
			brate=B14400;
			break;
#endif
		case 19200:
			brate=B19200;
			break;
#ifdef B28800
		case 28800:
			brate=B28800;
			break;
#endif
		case 38400:
			brate=B38400;
			break;
		case 57600:
			brate=B57600;
			break;
		case 115200:
			brate=B115200;
			break;
	}
	cfsetispeed(&toptions, brate);
	cfsetospeed(&toptions, brate);

	/* Use 8N1. */
	toptions.c_cflag &= ~PARENB;
	toptions.c_cflag &= ~CSTOPB;
	toptions.c_cflag &= ~CSIZE;
	toptions.c_cflag |= CS8;
	/* No flow control. */
	toptions.c_cflag &= ~CRTSCTS;

	//toptions.c_cflag &= ~HUPCL; // Disable hang-up-on-close to avoid reset.

	toptions.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines.
	toptions.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl.

	/* Make connection raw. */
	toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	toptions.c_oflag &= ~OPOST;

	/* See: http://unixwiz.net/techtips/termios-vmin-vtime.html */
	toptions.c_cc[VMIN] = 0;
	toptions.c_cc[VTIME] = 0;
	//toptions.c_cc[VTIME] = 20;

	tcsetattr(fd, TCSANOW, &toptions);
	if (tcsetattr(fd, TCSAFLUSH, &toptions) < 0) {
		perror("init_serialport: Couldn't set term attributes");
		return -1;
	}
	return fd;
}

/* Close the serial device file descriptor. */
int serialport_close(int fd)
{
	return close(fd);
}

/* Write 1 byte to serial device, return -1 on error. */
int serialport_writebyte(int fd, uint8_t b)
{
	int n = write(fd, &b,1);
	if (n != 1)
		return -1;
	return 0;
}

/* Write string to serial device, return -1 on error. */
int serialport_write(int fd, const char* str)
{
	int len = strlen(str);
	int n = write(fd, str, len);
	if (n != len) {
		perror("serialport_write: Couldn't write whole string\n");
		return -1;
	}
	return 0;
}

/* Read until specific character unless timeout or buffer maximum exceeded. */
int serialport_read_until(int fd, char* buf, char until, int buf_max, int timeout)
{
	char b[1];                  // read() expects an array, so we give it a 1-byte array.
	int i=0;
	do {
		int n = read(fd, b, 1); // Read one char at a time.
		if (n == -1) return -1; // Couldn't read.
		if (n == 0) {
			usleep(1 * 1000);   // Wait 1ms and try again.
			timeout--;
			continue;
		}
#ifdef SERIALPORTDEBUG
		printf("serialport_read_until: i=%d, n=%d b='%c'\n",i,n,b[0]); // Debug.
#endif
		buf[i] = b[0];
		i++;
	} while(b[0] != until && i < buf_max && timeout>0);

	buf[i] = 0; // Null terminate the string.
	return 0;
}

/* Flush I/O to serial device. */
int serialport_flush(int fd)
{
	sleep(2); // Required to make flush work, for some reason
	return tcflush(fd, TCIOFLUSH);
}
