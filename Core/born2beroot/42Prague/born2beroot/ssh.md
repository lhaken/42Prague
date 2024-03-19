# SSH
***
This part focuses on setting up a working and secure SSH so that we can access our VM from anywhere over the network.
***
## INSTALLING AND CONFIGURING SSH
Before we do anything, we need to make sure the system is up to date:
```
sudo apt update
```
Then we need to download the package with the tool that will allow us the SSH protocol:
```
sudo apt install openssh-server
```
> [!tip]- Check SSH service status
> 
> If you want to see proof, that the installation went well. You can check by executing
> ```
> sudo service ssh status
> ```
> If you can see **active (running)** everything went as planned and you may continue.

[[sudo#^167938 | Switch to the root user]] and run the following command to edit a config file of our SSH:
```
nano /etc/ssh/sshd_config
```
Find a line that reads "#Port 22" and change it to **"Port 4242"**.

> [!warning] Port 4242
> 
> On Prague 42's campus, the port 4242 is already occupied and therefore a default SSH port (22) or a different port must be used.

^cc277d

And a line that reads "#PermitRootLogin prohibit-password" and change it to **"PermitRootLogin no"**. Press **Ctrl + S** to save the changes and **Ctrl + X** to exit nano.

Also change the line with the port in the following config file: **/etc/ssh/ssh_config**

When done, we have to restart the SSH service so that it can load the new configuration. We do that by running:
```
sudo service ssh restart
```

Now head back to [[born2beroot#^509080 | the project guide]] and continue with the next step.
