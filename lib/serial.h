/*
 * Simple library for reading/writing Arduino serial device.
 *
 * This code was adapted from MIT licensed:
 *
 * > arduino-serial-lib
 * > 2006-2013, Tod E. Kurt, http://todbot.com/blog/
 */

#ifndef __ARDUINO_SERIAL_LIB_H__
#define __ARDUINO_SERIAL_LIB_H__

#include <stdint.h>	// Standard types.

int serialport_init(const char* serialport, int baud);
int serialport_close(int fd);
int serialport_writebyte( int fd, uint8_t b);
int serialport_write(int fd, const char* str);
int serialport_read_until(int fd, char* buf, char until, int buf_max,int timeout);
int serialport_flush(int fd);

#endif
