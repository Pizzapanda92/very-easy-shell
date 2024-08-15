#include "main.h"

//ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);
//char *strtok(char *restrict str, const char *restrict delim);
//pid_t fork(void);
//int execve(const char *pathname, char *const _Nullable argv[],
//pid_t wait(int *_Nullable wstatus);
//pid_t fork(void);


int main (void)
{
	char *input = NULL;
	size_t input_size;
	int max_args = 10;
	char * args[max_args];
	pid_t pid;

	while (1)
	{
		
		printf("$ ");

		if (getline(&input, &input_size, stdin) == -1)
		{
			perror ("getline failled");
		}

		/* Processing string input */
		input[strcspn(input, "\n")] = '\0';
		args[0] = input;
		args[1] = NULL;

		if (strcmp(input, "exit") == 0)
		{
			return (0);
		}

		/* gathering pid of processes and forking processes */
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			free(input);
			return (1);
		}


		/* child process execute */
		if (pid == 0)
		{


			/* executing a programm */
			printf("$ %s", input);
			if (execve(input,args,NULL) == -1)
			{
				perror("execve failled");
			}
			else
			{
				exit(EXIT_SUCCESS);
			}

		}
		else
		{
			wait(NULL);
		}
	}
}
