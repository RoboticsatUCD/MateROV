User Guide for Command Laptop
=============================
The command laptop, kymi, runs comprehensive setup of Arch Linux.
While it has a desktop installed, its usage paradigm may be unfamiliar to those unaccustomed to command line interfaces.
If you need a quick introduction or refresher, read the tutorials [here](http://linuxcommand.org/).

Most commonly used development, mathematics, and networking software are installed.
To see a [mostly] accurate list of what is installed, see the package list [here](https://github.com/egan/dotfiles/blob/master/pacman.txt).
Of special note is the fact that Python 3 is the default implementation of the Python language and libraries available.

Applications
------------
A small set of everyday graphical applications are installed.
Many have keyboard interfaces patterned after `vim`.

* Terminal emulator: Use `urxvtc`. Should you need it, `xterm` is also available.
* Web Browser: Both `firefox` and [`dwb`](http://portix.bitbucket.org/dwb/) are installed. Refer to the man page and the configuration at `~/.config/dwb/keys` for usage of the latter.
* Document Viewer: Use `zathura` for PDF, Deja Vu, and PostScript documents.
* Image View: Use `qiv` for static raster images and `animate` for animated ones.
* Media Player: Use `mplayer` to play audio or video files and feeds.

Window Manager
--------------
The installed window manager is spectrwm
