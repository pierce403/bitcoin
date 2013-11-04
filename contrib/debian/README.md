
Debian
====================
This directory contains files used to package hydracoind/hydracoin-qt
for Debian-based Linux systems. If you compile hydracoind/hydracoin-qt yourself, there are some useful files here.

## hydracoin: URI support ##


hydracoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install hydracoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your hydracoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/hydracoin128.png` to `/usr/share/pixmaps`

hydracoin-qt.protocol (KDE)

