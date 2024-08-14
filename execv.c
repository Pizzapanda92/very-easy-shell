#include <unistd.h>
#include <stdio.h>

int main() {
    char *argv[] = {"/usr/bin/ls", NULL}; // Arguments for the interpreter
    char *envp[] = {NULL}; // Use current environment

    if (execve("/usr/bin/ls", argv, envp) == -1) {
        perror("execve failed"); // Print error if execve fails
        return 1;
    }

    return 0; // This will not be reached if execve succeeds
}

