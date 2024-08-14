#include "main.h"

int main(void)
{

	char *cmd_prompt = NULL;
	size_t n = 70;
	size_t *max_len_cmd = &n;
	int toknum = 0;
	const char *delim = " ";
	char *args[n];
	char *token;
	char *prefix = "/bin/";
	
//	pid_t pid_child;

	/* prints prompt symbole*/
	printf("$ ");


	/* reads user input and store it in cmd_prompt*/
	if (getline(&cmd_prompt, max_len_cmd, stdin) == -1)
	{
		perror("getline failed");
	}



	/*tokenize cmd_promt*/
	token = strtok(cmd_prompt, delim);
	while (token != NULL)
	{
		args[toknum] = token;
		token = (strtok(NULL, delim));
		toknum++;

	}

	char pathname[20];
	snprintf(pathname, sizeof(pathname), "%s%s", prefix, args[0]);
	printf("%s",pathname);


/*
	//fork
	pid_child = fork()

		if (pid_child == -1)
		{	
			perror ("child dont work")
				return(1)
		}

	if (pid_child == 0)
	{
		if (execve(pathname, args, NULL) == -1)
	       	{
			perror("execve failed");
			return (1);
		}
	}
	else
	{
		wait (null)
	}	

	free(cmd_prompt);
	*/
	return 0;
}

