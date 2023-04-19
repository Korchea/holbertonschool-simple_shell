#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 */
int main(int argc, char *const *argv[], char *const *envp[])
{
	char *cmd;
	char *path;
	size_t size;
	int r;

	cmd = NULL;
	size = 0;

	while (1)
	{
		printf("$ ");
		r = getline(&cmd, &size, stdin);
		if (r == -1)
		{
			break;
		}
		if (fork() == 0)
		{
			wait(NULL);
			printf("%s", cmd);
		}
		else
		{
			path = getcwd(cmd, size);
			strcat(path, cmd);
			execve ((const char*) path, argv[0], *envp);
			printf("%s", path);
		}
	}
	free(cmd);
	return (0);
}
