#include "main.h"
#include <stdio.h>
#include <unistd.h>


int print_parent_pid(void)
{
	pid_t  print_parent = getppid();

	printf ("%d\n" , print_parent);

	return (0)
}
