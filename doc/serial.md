Serial Communication with Arduino
=================================
On Linux, the Arduino serial device is at `/dev/ttyACM*`.
It is important to set the correct baud rate, parity, etc. if you wish to communicate with it via the shell.

	stty -F /dev/ttyACM0 cs8 9600 ignbrk -brkint -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

Reading transmissions can be done simply with:

	tail -f /dev/ttyACM0

TTY interaction can be achieved with `picocom`.

XXX: More documentation necessary!
