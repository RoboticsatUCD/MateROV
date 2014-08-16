# Setup Arduino TTY to correct baud and parity.
stty -F /dev/ttyACM0 cs8 19200 ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

# Start jscommander.
./jscommander /dev/input/js0 > /dev/ttyACM0

# Read serial output.
tail -f /dev/ttyACM0
