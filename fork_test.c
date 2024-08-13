#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int create_child_and_execute()
{
    int i;
    pid_t pid_fils;
    char *argv[] = {"/bin/ls", "-l", "/very-easy-shell", NULL};
    extern char **environ; 

    for (i = 0; i < 5; i++)
    {
        pid_fils = fork();

        if (pid_fils == -1)
        {
            perror("Erreur lors de la création de l'enfant");
            return (1);
        }

        if (pid_fils == 0)
        {
            execve(argv[0], argv, environ);
            perror("Erreur lors de l'exécutin de execve");
            return 1;
        }
        else
        {
            wait(NULL);
        }
    }
    return (0);
}

int main(void)
{
    return create_child_and_execute();
}

