#include <stdio.h>

void print_av(char **argv)
{
	int index;

	for (index = 0; argv[index] != NULL; index++)
	{
		printf("%s\n", argv[index]);
	}
}


int main(int ac, char **av)
{
	print_av(av);
	return (0);
}
