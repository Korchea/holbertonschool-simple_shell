#include "main.h"

/**
 *
 */

int main(int argc, char *argv[], char *envp)
{
	char *cmd = NULL, *tok = NULL;
	size_t size = 0;
	int i = 0;

	while (printf("$ ") && getline(&cmd, &size, stdin) != -1)
	{
		/*tok = strtok(cmd, " \n"); //tok = strtok(cmd, " ");
		while(tok != NULL)
		{
			argv[i] = tok;
			tok = strtok(NULL, " \n");
			i++;
		}	*/
		argv = gettok(cmd, argv);
			execve(argv[0], argv, NULL);
	}
	free(cmd);
	return (0);
}
