#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void execute_command(char *input, char **env)
{
	char *args[BUFFER_SIZE];
	char *token;
	int i = 0;

	token = strtok(input, " \t\r\n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\r\n");
	}
	args[i] = NULL;

	if (args[0] == NULL) {
		// No command entered
		return;
	}

	pid_t pid = fork();
	if (pid < 0) {
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		/*Child process no env yet*/
		execve(args[0], args, env);
		perror("exec failed");
		exit(EXIT_FAILURE);
	} else {
		/* Parent process*/
		wait(NULL);
	}
}

int main(int argc, char **argv)
{
	char *input = NULL;
	size_t input_size = 0;
	int interactive = isatty(STDIN_FILENO);
	char **env = environ;

	if (argc > 1) {
		fprintf(stderr, "Usage: %s [no arguments]\n", argv[0]);
		return 1;
	}


	if (interactive) {
		while (1) {
			printf("$ ");
			if (getline(&input, &input_size, stdin) == -1) {
				if (feof(stdin)) {
					break; // End of input (Ctrl-D)
				}
				perror("getline failed");
				continue;
			}
			input[strcspn(input, "\n")] = '\0'; // Remove newline character
			if (strcmp(input, "exit") == 0) {
				break;
			}
			execute_command(input, env);
		}
	} else {
		while (getline(&input, &input_size, stdin) != -1) {
			input[strcspn(input, "\n")] = '\0'; // Remove newline character
			execute_command(input, env);
		}
	}

	free(input);
	return 0;
}
