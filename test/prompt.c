#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 */
int main(int argc, char *const *argv[], char *const *envp[])
{
	char *cmd;
	const char *path;
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
		printf("%s", cmd);
		path = getcwd(cmd, size);
		strcat(cmd, path);
		execve (path, argv[0], *envp);
	}
	free(cmd);
	return (0);
}
