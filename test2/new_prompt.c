#include "main.h"

/**
 *
 */

int main(int argc, char *argv[], char *envp)
{
	char *cmd, *tok;
	size_t size = 0;
	int r, i = 0;

 
	

	while (1)
	{
		printf("$ ");
		r = getline(&cmd, &size, stdin);
		if (r < 0)
			break;
		tok = strtok(cmd, " ");
		while(tok != NULL)
		{
			argv[i] = tok;
			tok = strtok(NULL, " ");
			i++;
		}
		printf("Before execve\n");
		if (execve(argv[0], argv, (char *const *)envp) == -1)
		{
			perror("Error:");
		}
		printf("After execve\n");
	}
	free(cmd);
	return (0);
}
