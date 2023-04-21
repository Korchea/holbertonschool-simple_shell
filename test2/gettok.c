#include "main.h"

/**
 * 
 */

char **gettok(char *cmd, char *argv[])
{
    char *tok = NULL, *cmd_cpy = strdup(cmd);
    int n_tok = 0, i = 0;

    tok = strtok(cmd, " \n");
    while (tok != NULL)
    {
        n_tok++;
        tok = strtok(NULL, " \n");
    }
    n_tok++;
    argv = malloc(sizeof(char *) * n_tok);
    tok = strtok(cmd_cpy, " \n");
    for (i = 0; tok != NULL; i++)
    {
        argv[i] = malloc(sizeof(char) * strlen(tok));
        strcpy(argv[i], tok);
    }
    argv[i] = NULL;
    free(cmd_cpy);
    return (argv);
}