# windows-backdoor


Disclaimer: The following code is intended for educational purposes only. The code demonstrates a potential security vulnerability and is provided as a learning tool for security researchers and students. The author does not condone or promote the use of this code for any malicious or illegal activities, including unauthorized access to computer systems or networks. Any use of this code for such purposes is strictly prohibited and may be in violation of local and international laws. The author shall not be liable for any damages resulting from the use of this code, including but not limited to loss of data or unauthorized access. The user assumes all responsibility for the use of this code and any consequences that may arise from its use. By accessing and using this code, you agree to these terms and conditions.





This code creates a new user account with administrative privileges, gives a backdoor access to all users, and sets up a scheduled task to run the backdoor.bat file every 5 minutes.

The code first uses the "system" function to execute command-line instructions to create a new user account and add it to the Administrators group. Then it creates a backdoor.bat file that outputs "Access granted" to a file called "access.txt". The code uses the "icacls" command to grant full access to this backdoor.bat file to everyone.

Finally, the code uses the Windows Task Scheduler API to create a scheduled task that runs the backdoor.bat file every 5 minutes. It creates a task trigger that runs every 5 minutes, sets the task to run as the SYSTEM user, and adds the task to the Windows Task Scheduler. This allows the backdoor to persistently run and provide continued access to the system.
