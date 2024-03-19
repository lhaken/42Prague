# PASSWORD 💪
***
One of the featuresof our server should be a strict password policy. The rules of this policy can be found under the [[#REQUIREMENTS ✅ | requirements]] heading.
***
## SETTING UP A STRONG PASSWORD POLICY
As per the subject, here is how the policy should work:
***
### REQUIREMENTS ✅
- [.] password has to expire every 30 days
- [.] mininum of 2 days allowed before the modification of a password
- [.] warning message 7 days before the password expires
- [.] atleast 10 characters long (uppercase, lowercase, number and cannot include more than 3 consecutive same characters)
- [.] cannot include the name of the user
- [.] password must have atleast 7 characters that were not part of the previous password (doesn't apply to root)
- [.] root password has to comply with the policy
***
First, we need to set up the first 3 rules. We do that by opening and editing a file:
```
nano /etc/login.defs
```
There we have to configure 3 things:
1) **Password expires every 30 days**
	```
	PASS_MAX_DAYS 30
	```
2) **Minimum 2 days before modification**
	```
	PASS_MIN_DAYS 2
	```
3) **Warning 7 days before password expires**
	```
	PASS_WARN_AGE 7
	```

When we have these 3 rules implemented, we can save and exit the file and continue with configuring the rest. We can start by installing the **libpam-pwdquality** package:
```
sudo apt install libpam-pwdquality
```
When we're done installing the package, we can configure it's config file to implement our rules:
```
nano /etc/pam.d/common-password
```
In this file we have to find a line that reads...
```
password requisite pam_pwquality.so retry=3
```
...and change it to the following:
```
password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

#todo check difok

#### Table of commands
| Command | Usage |
| --- | --- |
| minlen | Sets the minimum lenght of the password |
| ucredit | Sets how many upper case letters there should be |
| lcredit | Sets how many lower case letters there should be |
| dcredit | Sets how many digits there should be |
| maxrepeat | Sets the maximum of repeating characters |
| reject_username | Rejects passwords that contain a username |
| difok | Sets how many characters can be shared between two passwords |
| enforce_for_root | Applies the policy for the root password as well |


> [!tip]- What does the minus do?
> 
> It basically sets the minimum value of a rule. For example if there would be no minus in front of the number that is assigned to ucredit, that would mean that the maximum number of capital letters would have to be 1 - rendering the password: HelloWorld invalid.

Now that all the rules are set up, head back to [[born2beroot#^8250ea | the project guide]] and continue with the next step.