#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *
 */
int main(void)
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
		if (command == "-1")
			break;
		printf("%s", command);
	}
	free(command);
	return (0);
}
