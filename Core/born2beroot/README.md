# HOW TO: BORN2BEROOT
## VM SETUP

1) go to debian.org and click on Download (as of 21.02.2024 the "stable" version is Debian 12 (code name: Bookworm) - latest release 12.5)
2) open VirtualBox > click on "New" > name your virtual machine > select machine folder (/goinfre) > select type (Linux) & version (Debian (64-bit)) > click continue
3) select memory size (1024 MB) > click continue
4) create a virtual hard disk > click continue
5) select VDI as you hard disk file type > click continue
6) select storage to be dynamically allocated > click continue
7) select file size (12GB) > click continue

Now your VM should be visible on the left in the VirtualBox window

8) while you have your VM selected, click on "Settings" and select "Storage"
9) for Controller: IDE, click on the CD icon next to the "Optical drive" drop down menu > click on "Choose a disk file" > find and select you downloaded Debian image (debian-12.5.0-amd64-netinst.iso) > click in the image file under "Controller: IDE" > click ok
10) click on "Start"
