#include "shell.h"

/**
 * 
 */

int main(int argc, char **argv, char **envp)
{
    char *cmd = NULL, *taux = " \0", *tok[128] = {};
    size_t size = 0;

    while (printf("$ ") && getline(&cmd, &size, stdin) != -1)
    {
        tok[0] = strtok(cmd, taux);
        while (tok)
        printf("%s", cmd);
    }
    return (0);
}