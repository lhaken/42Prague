# UFW
***
This part of the project focuses on setting up a solid firewall rules to further solidify our VM's security.
***
## INSTALLING AND CONFIGURING UFW
First we need to install UFW by running:
```
sudo apt install ufw
```
When the installation is finished, we can turn the service on:
```
sudo ufw enable
```
After starting the firewall up, we need to implement our rules, in our case [[ssh#^cc277d | only allowing traffic to go to port 4242]]. We do that by typing and executing:
```
sudo ufw allow 4242
```
> [!tip]- Opened ports
> 
> To see what ports are allowed to accept traffic, execute:
> ```
> sudo ufw status
> ```

Now head back to [[born2beroot#^62d529| the project guide]] and continue with the next step.