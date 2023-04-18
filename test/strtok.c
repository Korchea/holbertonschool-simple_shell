#include <string.h>
#include <stdio.h>
/**
 *
 */
int mainalgo()
{
	char str[80] = "Print something mf";
	const char s[2] = " ";
	char *token;

	token = strtok(str, s);

	while (token != NULL)
	{
		printf(" %s\n", token);
		token = strtok(NULL, s);
	}
	return (0);
}
