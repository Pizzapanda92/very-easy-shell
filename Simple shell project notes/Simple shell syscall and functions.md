all functions from string.h


| syscall name | librairie   | function | syscall | purpose                                                                                                              |
| ------------ | ----------- | -------- | ------- | -------------------------------------------------------------------------------------------------------------------- |
| access       | unistd.h    |          | x       | check if process can access the file in pathname                                                                     |
| chdir        | unistd.h    |          | x       | change current directory to a specified one                                                                          |
| close        | unistd.h    |          | x       | closes a file descriptor                                                                                             |
| closedir     | sys/types.h | x        |         | closes directory stream associated with dirp                                                                         |
| execve       | unistd.h    |          | x       | replace the calling process by the program it execute, either a binary file or a script.                             |
| exit         | stdlib.h    | x        |         | normal process termination, returns lest significant byte to the parent process                                      |
| _exit        | stdlib.h    | x        |         | terminates a process immediately, closes its file descriptor and attached child to the parent (sends also a SIGCHLD) |
| fflush       | stdio.h     | x        |         | writes all buffer data in user's space for a given output                                                            |
| fork         | unistd.h    |          | x       | duplicates a process and makes it is child. new PID and is in another space in the memory                            |
| free         | stdlib.h    | x        |         | free a pointer allocated dynamically                                                                                 |
| getcwd       | unistd.h    | x        |         | returns the absolute path of the current working directory                                                           |
| getline      | stdio.h     | x        |         | read an entire line from a stream including null terminator, has to be freed.                                        |
| getpid       | unistd.h    |          | x       | returns pid of the calling process                                                                                   |
| kill         | signal.h    |          | x       | kill a process and depending on the value of the signal sent terminates the child.                                   |
|              |             |          |         |                                                                                                                      |

opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
