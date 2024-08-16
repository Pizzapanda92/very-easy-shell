#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;
int read_one_by_one();
int readline(void);
int print_parent_pid(void);


#endif
