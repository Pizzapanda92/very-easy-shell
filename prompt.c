#include <stdio.h>
#include <unistd.h>


int print_parent_pid(void)
{
	pid_t  print_parent = getppid();

	printf ("%d\n" , print_parent);

	return (0);
}



int main(void)
{
	print_parent_pid();
		return (0);
}
