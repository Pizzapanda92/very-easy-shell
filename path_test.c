#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char *path_env = NULL;
	char *path_copy = NULL;
	struct stat st;
	char *dir = NULL;
	char full_path[1024];
	int found = 0;
	int i;

	// recup la variable path
	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		perror("getenv");
		return 1;
	}

	//copier la variable path pour la decouper

	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup fail");
		return (1);
	}

	//verifie que le nombre dargument est bon

	if (ac < 2)
	{
		printf("Usage: %s filename ...\n", av[0]); 
		free(path_copy);
		return (1);
	}




	for (i = 1; i < ac; i++)
	{
		dir = strtok(path_copy, ":"); //decouper path


		while (dir != NULL)
		{


			snprintf(full_path, sizeof(full_path), "%s/%s", dir, av[i]); //construire le chemin complet

			if (stat(full_path, &st) == 0) //verif si le fichier existe
			{
				printf ("%s\n", full_path);
				found = 1; //flag pour indiquer que le fichier a ete trouve 
				break;
			}

			dir = strtok(NULL, ":");
		}

		if (!found)
		{
			printf("%s: NOT FOUND\n", av[i]);
		}

		free(path_copy);
		path_copy = strdup(path_env);

		if (path_copy == NULL)
		{
			perror("strdup fail");
			return (1);
		}

		found = 0;
	}

	free(path_copy);
	return(0);
}

