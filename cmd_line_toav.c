#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (void)
{
	char str[] = "This is a sentence";
	char *token = strtok(str, " ");
	
	while (token != NULL)
	{
		printf("%s\n",token);
		token = strtok(NULL, " ");
	}
	return (0);
}
