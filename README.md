# windows-backdoor


Disclaimer: The following code is intended for educational purposes only. The code demonstrates a potential security vulnerability and is provided as a learning tool for security researchers and students. The author does not condone or promote the use of this code for any malicious or illegal activities, including unauthorized access to computer systems or networks. Any use of this code for such purposes is strictly prohibited and may be in violation of local and international laws. The author shall not be liable for any damages resulting from the use of this code, including but not limited to loss of data or unauthorized access. The user assumes all responsibility for the use of this code and any consequences that may arise from its use. By accessing and using this code, you agree to these terms and conditions.





The code creates a backdoor on a Windows machine by performing the following actions:

Creating a new user account named "Administrator" with administrative privileges.
Adding the newly created "Administrator" account to the "Administrators" group.
Creating a new batch file called "backdoor.bat" in the "C:\Users\Public" directory.
Writing the message "Access granted" to a text file called "access.txt" using the "echo" command within the "backdoor.bat" file.
Granting all users full access to the "backdoor.bat" file using the "icacls" command.
The end result of this code is that an attacker can run the "backdoor.bat" file and gain access to the system with administrative privileges, effectively creating a backdoor that bypasses security controls.

