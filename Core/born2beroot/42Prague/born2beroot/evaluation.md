# EVALUATION 🔍
***
In this document you can find all the informations that are relevant when you reach your evaluation.
***
### EVAL TASKS ❗
> [!danger]- Create a user and assign it to a group
> To create a user we use this command:
> ```
> sudo adduser [username]
> ```
> After creating the user, we have to enter a password that follows our password policy. To add a user into a group we need to make sure the group exists. If it doesn't we can simply create it by executing:
> ```
> sudo addgroup [name of the group]
> ```
> And when we know our group exists, we can add the user to the group by running:
> ```
> sudo adduser [username] [name of the group]
> ```
> To check if we added the user to the group we can do:
> ```
> getent group [name of the group]
> ```

> [!danger]- Check GUI
> a
> To check if a Graphical User Interface is running we can run a command:
> ```
> ls /usr/bin/*session
> ```
> and the output should be:
> ```
> /usr/bin/dbus-run-session
> ```

> [!danger]- Check UFW
> 
> To check if UFW is running execute:
> ```
> sudo ufw status
> ```
> or
> ```
> sudo service ufw status
> ```

> [!danger]- Check SSH
> To check if SSH is running execute:
> ```
> sudo service shh status
> ```

#todo fill in all the eval tasks
***
### EVAL QUESTIONS ❓
> [!faq]- Why did you choose Debian?
> 
> I used to have it on my own server at home, so it was an easy choice. From then I switched to Ubuntu.
^912e55

> [!faq]- What are some basic differences between Debian and CentOS?
> 
> CentOS is more stable and production servers are usually hosted on it, however Debian is much more beginner friendly with support for a much wider variety of packages. CentOS also edges Debian in terms of Desktop apps (10+ years of development).

> [!faq]- What is the purpose of a virtual machine?
> 
> A virtual machine has many upsides. Two of the more major ones would be splitting the resources of 1 machine into many more. The second major thing VMs have going for them is having a way to test apps and other things on multiple different architectures without having to own them.

> [!faq]- What's the difference between aptitude and apt?
> 
> The short answer would be that aptitude is smart. The long answer is that aptitude remembers all dependencies and when uninstalling something it uninstalls everything that is not needed, while apt would uninstall only the explicitly requested packages.

> [!faq]- What is SELinux and AppArmor?
>
> SELinux means Security-Enhanced Linux and it's an extension of the Linux kernel focused on system security. AppArmor is an application security system for Linux - so it allows for app explicit permissions, it basically protects the system from apps.

#todo fill in all the eval questions