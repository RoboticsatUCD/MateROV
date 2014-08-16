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

* Terminal emulator: Use [`urxvtc`](http://software.schmorp.de/pkg/rxvt-unicode.html). Should you need it, `xterm` is also available.
* Web Browser: Both `firefox` and [`dwb`](http://portix.bitbucket.org/dwb/) are installed. Refer to the man page and the configuration at `~/.config/dwb/keys` for usage of the latter.
* Document Viewer: Use [`zathura`](http://pwmt.org/projects/zathura/) for PDF, Deja Vu, and PostScript documents.
* Image View: Use [`qiv`](http://spiegl.de/qiv/) for static raster images and [`animate`](http://www.imagemagick.org/script/animate.php) for animated ones.
* Media Player: Use [`mplayer`](http://www.mplayerhq.hu) to play audio or video files and feeds.

Window Manager
--------------
The installed window manager is [`spectrwm`](https://github.com/conformal/spectrwm/wiki), efficient and tiling.
It may be alien to users of stacking window managers: refer to the man page and the configuration in `~/.spectrwm*` for in depth information.

### Basic Usage:
Opening windows:
* Open run prompt: M+z
* Open new terminal emulator: M+x
* Open web browser: M+i (dwb), M+I (firefox)
* Open document viewer: M+p
* Open latest pdf in `~/var`: M+P
* Open `vim` (execd): M+v
* Open `gvim`: M+V

Windows:
* Next/previous window: M+Tab/S+Tab, M+j/k
* Switch to master window: M+m
* Move window up/down: M+J/K
* Trade window with master: M+Enter
* Maximize/restore window: M+e
* Hide/restore window: M+w/W
* Select window: M+f
* Toggle tiling: M+t

Workspaces:
* Switch to workspace 1-22: M+1-0,F1-F12
* Switch to prior workspace: M+\`
* Switch to next/previous workspace (all): M+Up/Down
* Switch to next/previous workspace (used): M+Right/Left
* Name workspace: M+?
* Search workspace names: M+/
* Move current window to workspace 0-22: M+S+1-0,F1-F12

Layouts:
* Switch to next layout: M+Space
* Restore default layout: M+S+Space
* Grow/shrink stack: M+h/l
* Add/remove window to/from master: M+,/.
* Add/remove column to/from stack: M+<,>

Quitting:
* Restart window manager: M+Delete
* Quit window manager (close windows first!): M+S+Delete
* Close window (try to do this from application first!): M+q
