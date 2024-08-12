In this section we'll answer the questions related to how does the shell works.

#### How does the shell works:

#### What is a pid and a ppid

The PID is the process identifier. It permits to identify processes. Every Processes have a parent processes which is identified by its PPID.  This looks pretty similar to the node data structure we have seen in [[Lists]].  

Processes can create other processes which will in turn become its children and the current processes would become its parent. 

To visualize the processes in the shell type the command ps or man ps first. 



#### How to manipulate the environment of the current process

The environnement of a process is a collection of environment variables. Those environment variable are dynamic variable the influence the behavior of a program. Every  process is associated with its set of environment variable. Some environment variable are exported by its parent process, and the process can ads its own variable to the list. Because of this it is important to understand the two categories of environment variables. 

**Global environment variable:

Those are variables that every child processes can use. For instance the PATH variable is available globally.

**Local environment variable:

Those are variable only accessible for a program or a session. Let's say I create an alias like so:

``` shell
alias myfunc="cd yourmama/"
```

This variable is not stored in the global ./bashrc file, therefore would not be accessed later.  All in all it is similar to the constant and local variable in [[The C language]]. 

Environment variables are all CAPITALIZED. like PATH. 

To access the environment variables we can use the following command line:

```shell
echo $PATH
```
This will display the location of this variable or **its value**.

To access the list of all the **global environment variable** use this command

```Shell
printenv 
env
```

To display the **local and global** environment variable you can use
```shell
set
```

To create global variable it is the export function

```Shell
export myfunc="cd yourmama/"
source /etc/.bashrc
```
**Some commonly used ENV in Linux**

| **Environment Variables** | ****Description****                             |
| ------------------------- | ----------------------------------------------- |
| **$USER**                 | Gives search path for commands.                 |
| **$PATH**                 | Gives search path for commands.                 |
| **$HOME**                 | Gives path of home directory.                   |
| **$PWD**                  | Gives the path of present working directory.    |
| **$HOSTNAME**             | Gives name of the host.                         |
| **$LANG**                 | Gives the default system language.              |
| **$EDITOR**               | Gives default file editor.                      |
| **$UID**                  | Gives user ID of current user.                  |
| **$SHELL**                | Gives location of current user’s shell program. |
#### What is the difference between a function and a system call:

Abstractly a system call is a way for the program to transition from user space to kernel space. We can say a function provides a greater level of abstraction than a sys-call. 

![[syscall_vs_libraryfunc.jpeg]]

 ![[system-call-steps-execution.png]]
 
 
#### How to create processes


- What are the three prototypes of `main`
- How does the shell use the `PATH` to find the programs
- How to execute another program with the `execve` system call
- How to suspend the execution of a process until one of its children terminates
- What is `EOF` / “end-of-file”?
https://en.wikipedia.org/wiki/Here_document
