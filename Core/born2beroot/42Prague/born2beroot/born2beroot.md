# HOW TO: BORN2BEROOT
***
This project is about virtualization and setting up our very own SSH server.
***
## CONTENTS
[[#PROJECT GUIDE | 1 ..... PROJECT GUIDE]]
> [[#1) Downloading an operating system | 1.1 ..... Downloading an operating system]]
> [[#2) Installing a virtual machine | 1.2 ..... Installing a virtual machine]]
> [[#3) Installing an operating system | 1.3 ..... Installing an operating system]]
> [[#4) Configuring the VM | 1.4 ..... Configuring the VM]]
> [[#5) Connecting via SSH | 1.5 ..... Connecting via SSH]]
> [[#6) The monitoring script | 1.6 ..... The monitoring script]]
> [[#7) Generating the signature | 1.7 ..... Generating the signature]]
***
## PROJECT CHECKLIST ✅
In order to track our progress, we need to create a simple checklist of the things we are supposed to do according to the subject:
***
- [.] choose an operating system
- [.] create atlease 2 encrypted partitions using [[vocab#^766f15 | LVM]]
- [.] [[vocab#^039c1a| SSH]] service on port 4242 (can't connect as root)
- [.] [[vocab#^7c43c8| UFW]] (leaving only port 4242 open)

> [!warning] Port 4242
> 
> On Prague 42's campus, the port 4242 is already occupied and therefore a default SSH port (22) or a different port must be used.

- [.] hostname has to be my login ending with 42 (lhaken42)
- [.] [[password | strong password policy]]
- [.] install and configure [[sudo | sudo with strict rules]]
- [.] a user with my login as username has to be present (lhaken) and has to be part of groups: sudo & user42
- [.] a [[monitoring | monitoring]] script
- [ ] create and hand in a signature
***
## PROJECT GUIDE
### 1) Downloading an operating system
This part is pretty simple. We are going with Debian, that we can download for free from [the Debian website](https://www.debian.org/). If we click on Download on the landing page, it should download the latest stable version of Debian. As for why I chose Debian, you cen refer to [[evaluation#^912e55 | this answer]].

### 2) Installing a virtual machine
When we have the .iso file downloaded, we can fire up VirtualBox and click on **New** on the top bar. That opens up a new window where we have to name the virtual machine - this name doesn't really matter, however I recommend naming it "born2beroot" or something similar. We also have to choose where we want to store our VM.

> [!warning] VM location
> 
> Each session on a 42 computer has a limited storage allocated. If we were to install the VM in our session we would run out of space. That's why we have to store it inside our sgoinfre folder.
> 
> /sgoinfre/goinfre/Person/lhaken

We also choose **Linux** as our Type and **Debian (64-bit)** as our Version. On the next screen, we select **1024 MB of RAM** for our machine. Later we select **Create a virtual hard disk now**. For the hard disk file type we will choose **VDI (VirtualBox Disk Image)**. We want the storage to be **Dynamically allocated**. On the next screen, the file location should be correct, however for size, **12 GB** is recommended.

Now we're almost done with the VirtualBox settings. One last thing you have to do is head over to **Settings** of you VM. Select **Storage** and click on the field that says Empty with a disk icon next to it. Click on the CD icon on the far right of the screen and then click on **Choose a disk file...**. Find and select your [[#1) Download an operating system | previously downloaded .iso file]]. Confirm the configuration by clicking on **OK**. When you're ready to move onto the Debian configuration, press **Start** on the top bar in VirtualBox.

### 3) Installing an operating system

> [!tip]- Screen size
> 
> By default the VM screen is rather small you can adjust it by right clicking on the screen icon on the bottom bar, then Virtual Screen 1 and selecting a scale.

Now we can begin with configuring our Debian machine. On the first screen we have to choose **Install** to comply with the subject. You can then choose any language for the machine, but i strongly recommend **English** as it's very universal. Select the country you're currently in. For locales it's recommended to choose **United States** and you can select your preferred keyboard layout and proceed with the configuration. 

Now comes the important part. Your hostname has to be your intra login ending with 42, for me that's **lhaken42**. When asked to enter a domain name, leave that field empty and just **Continue**. Select a root password, doesn't really matter what it is now as you'll have to change it to go by our [[password | password policy]], just something easy to remember. Retype the password to confirm it.

> [!tip]- What did I type?!
> 
> If you want to see what you typed, select the "Show Password in Clear" field and press Spacebar.

Now we can move on to setting up a new user. Set the full name and username for a new user. Thinking ahead we can select the username of the user to be our login (so for me it's **lhaken**), since we would need a user with that name later on anyway according to the subject. Setting the password is the same as with the root user.

Now we are done with users and we can move to to partitioning. Select **Guided - use entire disk and set up encrypted LVM** (or select **Manual** if you want to do bonus). Select a disk (there should only be 1 present) and once a disk has been selected choose to **Separate /home partition**. When asked about writing the changes to the disk select **Yes** then **Cancel** the process of erasing data (we don't need that as the disk is empty). When prompted with entering an encryption passphrase proceed as you would with entering a password. On the next screen enter the amout of volume group to use for guided partition as **max**. To finish the partitioning select **Finish partitioning and write changes to disk** and confirm the changes by selecting **Yes**.

When asked about scanning extra installation media to configure a package manager select **No**. Choose your country and then **deb.debian.org**. Leave the proxy field empty and **Continue**. On the screen about participating in the package usage survey select **No**.

When prompted with software selection uncheck everything, then press **Continue**. When asked about installing the GRUB loader, click on **Yes**. On the next screen select **/dev/sda** as a device for your boot loader installation. And finish with **Continue** on the screen where it says "Finish the installation".

### 4) Configuring the VM
When starting our VM select **Debian GNU/Linux** and when prompted type your encryption passphrase and then proceed to log in.

Now we have to [[sudo#INSTALLING AND CONFIGURING SUDO | install and configure sudo for our user]]. ^88ea66

When we are done with configuring sudo, we can move onto [[ssh#INSTALLING AND CONFIGURING SSH | the installation and configuration of SSH]]. ^509080

After installing and configuring the SSH, we can do a similar thing with [[ufw#INSTALLING AND CONFIGURING UFW| UFW]]. ^62d529

Now it's time to [[sudo#IMPLEMENTING STRICT RULES | implement strict sudo rules]]... ^3b2b64

...and [[password#SETTING UP A STRONG PASSWORD POLICY | set up a strong password policy]]. ^8250ea

### 5) Connecting via SSH
To set up the SSH connection we have to close the machine and go to **Configuration** of our VM in our VirtualBox window. Once the configuration window opens, click on **Network**, then click on **Advanced** and after that click on **Port forwarding**. Create a new rule with the **green icon** in the top right corner and type **4242** as both ports. Save the settings.

> [!tip]- How to connect?
> 
> Head over to your terminal and type:
> ```
> ssh lhaken@localhost -p 4242
> ```
> When prompted, enter your password and you should be connected to you VM using SSH.

### 6) The monitoring script
Now it's time to implement [[monitoring#SCRIPT 📝 | the monitoring script]].  ^aeca0b

When we're done with the script let's set up the [[vocab#^264861 | cron]] job. To edit the cron configuration we have to open the config files by execuring:
```
sudo crontab -u root -e
```
Then we can add the following line to execute the monitoring script every 10 minutes:
```
*/10 * * * * sh /home/lhaken/monitoring.sh
```
By adding the line above, our Cron configuration should be ready.

### 7) Generating the signature
> [!warning] This is the very last step
> 
> Generating the signature.txt is the very last step before we are ready for our evaluation. If we turn the VM on or modify anything the signature changes, therefore we have to do this as the very last step, after we made sure everything is working and we have all our commands ready for the evaluation.

When ready to generate the **signature.txt**, close the VM and find the location od the **.vdi file** in your terminal. Run:
```
sha1sum born2beroot.vdi
```
Copy the output of the **signature.txt** file and you're done with this project. Congratulations!!!
***
#### Tester
#todo insert tester link

#### Links
https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md
https://github.com/pasqualerossi/Born2BeRoot-Guide