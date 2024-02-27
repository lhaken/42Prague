# HOW TO: BORN2BEROOT 💻

## VM DOWNLOAD & INSTALL 📥

1) go to https://debian.org and click on Download 📥 (as of 21.02.2024 the "stable" version is Debian 12 (code name: Bookworm) - latest release 12.5)
2) open VirtualBox 📦  click on "New" 🔵 > name your virtual machine > select your machine folder 📁 (/goinfre) > select the OS type (Linux) & a version (Debian (64-bit)) > click on "Continue" 🔵
3) select the memory size 💾 (1024 MB) > click on "Continue" 🔵
4) create a virtual hard disk > click on "Continue" 🔵
5) select VDI as you hard disk file type > click on "Continue" 🔵
6) select storage to be dynamically allocated > click on "Continue" 🔵
7) select file size (12GB) > click on "Continue" 🔵

Now your VM should be visible on the left in the VirtualBox window.

8) while you have your VM selected, click on "Settings" 🔧 and select "Storage" 💾
9) in Controller: IDE, click on "Optical drive" 💿 drop down menu > click on "Choose a disk file" > find and select you downloaded Debian image (debian-12.5.0-amd64-netinst.iso) > click on the image file under "Controller: IDE" > click on "OK" 🔵
10) click on "Start"  🟢

## VM SETUP 🔧

1) select "Install" > select a language 🗨️ > select your country 🌍 > select your keyboard layout ⌨️
2) create a host name: lhaken42 ([your_login]42)
3) when asked to enter a domain name, leave it empty
4) create a password for the host name (something you will easily remember)
5) create a different user (can be anything - lhaken, basic_user etc.)
6) create a password for the new user (you can use the same one as for your host)
7) select a time zone
8) when partitioning a disk select "Guided - use entire disk and set up encrypted LVM" (LVM - Logical Volume Management)
9) select your disk
10) from partitioning schemes choose "Separate /home, /var, and /tmp partitions"
11) select "Yes" when asked about writing to the disk
12) create an encryption passphrase & verify it on the next screen (again something easy to remember or write it down)
13) type "max" when asked about the amount of volume group to use for guided partitioning
14) Finish the partitioning & confirm the writing of the changes
15) when asked about scaning a CD / DVD for a package manager select "no"
16) select your country & on the next screen find "deb.debian.org"
17) leave the HTTP proxy info empty and continue
18) select "No" when asked about participation in the package usage survey
19) when selecting software use space to select / unselect items and only select "Standard system utilities" & "SSH server" (be carefull as "Debian desktop environment" and "GNOME" are selected automatically)
20) when asked about GRUB boot loader select "Yes" & select "/dev/sda" on the next screen
21) press "Continue" on the "Finish the installation" screen
