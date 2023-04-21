#include "main.h"

/**
 *
 */

int main(void)
{
	char *cmd = NULL, *tok = NULL, *_env[] = {_getenv("PATH"), NULL}, *cmd_cpy = NULL, **argv;
	size_t size = 0;
	int i = 0, n_tok = 0;

	while (printf("$ ") && getline(&cmd, &size, stdin) != -1)
	{
		if (fork() == 0)
		{
			cmd_cpy = strdup(cmd);
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
				tok = strtok(NULL, " \n");
			}
			argv[i] = NULL;
			free(cmd_cpy);
			execve(argv[0], argv, _env);
		}
		else
		{
			wait(NULL);
			/*for (; i >= 0; i--)
				free(argv[i]);
			if (argv != NULL)
			{
				free(argv);
			}*/
		}
	}
	
	free(cmd);
	return (0);
}
