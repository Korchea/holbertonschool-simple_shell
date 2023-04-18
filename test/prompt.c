#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *
 */
int main(int argc, char *const *argv[], char *const *envp[])
{
	char *command;
	size_t size;
	int r;

	command = NULL;
	size = 0;

	while (1)
	{
		printf("$ ");
		r = getline(&command, &size, stdin);
		if (r == -1)
		{
			break;
		}
		printf("%s", command);
		execve (command, argv[0], *envp);
	}
	free(command);
	return (0);
}
