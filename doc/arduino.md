Using Arduino
=============
Arduino projects can be managed, built, uploaded, etc. using the utilities provided by the [ino package](http://inotool.org/).
If you prefer not to work manually with avr utilities, this is the recommended package to use for working with Arduino.
Notably, it handles some of the code preprocessing so you do not need to worry about writing proper C code to be compiled with `avr-gcc`.

A Makefile is also available on the web to handle the manual procedure more easily.
Otherwise, the main procedure for using Arduino is to write complete code, compile it with the right target parameters using `avr-gcc`, and use `avrdude` to upload and manipulate the Arduino ROM/EEPROM.
