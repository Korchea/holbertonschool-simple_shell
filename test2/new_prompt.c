#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 */

int main(void)
{
	char *cmd, *tok, *argv[10];
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
			printf(" %s\n", tok);
			tok = strtok(NULL, " ");
			i++;
		}
		printf("Before execve\n");
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
		printf("After execve\n");
	}
	free(cmd);
	return (0);
}
