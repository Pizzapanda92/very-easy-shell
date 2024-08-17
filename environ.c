#include <stdio.h>
#include<stdlib.h>
#include "main.h"


int main (void)
{
	char **env = environ;
	char *key;
	char *value;

	while (*env)
	{
		key = strtok(*env, "=");
		value = strtok(NULL, "=");
		if (strcmp(key, "USER") == 0)
		{
			printf("This is the key: %s\n", key);
			printf("This is the value: %s\n", value);
		}
		env++;
	}
	return (0);
}
