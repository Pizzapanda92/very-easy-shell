#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
int
main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("/etc/motd", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Réception d'une ligne de longueur %zu :\n", read);
        printf("%s", line);
    }
    free(line);
    exit(EXIT_SUCCESS);
}
