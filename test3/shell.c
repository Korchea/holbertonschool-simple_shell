#include "shell.h"

/**
 * 
 */

int main(int argc, char **argv, char **envp)
{
    char *cmd = NULL, *taux = " \0", *token = NULL, *tok[128] = {};
    size_t size = 0;
    int i = 0;

    while (printf("$ ") && getline(&cmd, &size, stdin) != -1)
    {
        token = strtok(cmd, taux);
        while (token)
        {
            tok[i] = token;
            printf("%s\n", tok[i]);
            token = strtok(NULL, taux);
            i++;
        }
    }
    free(cmd);
    return (0);
}