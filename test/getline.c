#include <stdio.h>
#include <stdlib.h>
/**
 *
 */
int main()
{
	char *command;
	size_t size;

	command = NULL;
	size = 0;

	while (1)
	{
		printf("$ ");
		getline(&command, &size, stdin);
		printf("%s", command);
	}
	free(command);
	return (0);
}
