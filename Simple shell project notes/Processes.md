 At the start of a command a process is initialized, there is two ways to initialise a process. 

#### **foreground processes**

Every processes starts in the foreground by default, as they are waiting for input from the keyboard. 

When a command is running in the foreground and is taking a lot of time no other processes can be run or started. It waits for this process to finish. 

#### background processes

When in the background the processes waits till the keyboard input is required. So it can be done in parallel. 

#### Types of processes

Parent and child processes are fairly easy to understand. 

**Zombie and orphan** 

When a program is terminated using the kill syscall a signal updates the parent process about the termination. Although if the parent process is terminated before killing the child, this one becomes orphan and this orphan is not in use anymore although its environment variables are updated with the parent's one. 

**Daemon processes**

Daemon processes are related to the system, the often work with the root permission and in the background. 

Fun fact:

The name comes from the "though experiment" of maxwell's demon, although it just means that the Daemon process works tirelessly behind the scene ;) 



