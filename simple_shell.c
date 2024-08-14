#include "main.h"

int main(void)
{

	char *cmd_prompt = NULL;
	size_t n = 70;
	size_t *max_len_cmd = &n;
	int toknum = 1;
	char *args[n];
	char *token = strtok(cmd_prompt, delim);
	args[0] = "-c";
	const char *delim = " ";
	
	/* prints prompt symbole*/
	printf("$ ");


	/* reads user input and store it in cmd_prompt*/
	if (getline(&cmd_prompt, max_len_cmd, stdin) == -1)
	{
		perror("getline failed");
	}


	/*tokenize cmd_promt*/
	while (token != NULL)
	{
		args[toknum] = token;
		token = (strtok(NULL, delim));
		toknum++;

	}
	

	char *pathname = args;

	//fork
	
	execve(pathname, args, NULL); 
	printf("print from cmd prompt %s\n", cmd_prompt);
	free(cmd_prompt);
	return 0;
}

