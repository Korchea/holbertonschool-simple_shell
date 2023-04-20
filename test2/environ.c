#include "main.h"
#include <string.h>
/**
 */
char *main(char *envp)
{
	int i;
	char *pathname = "PATH=";
	char *separator = " ";
	char *token;

	token = strtok(pathname, separator);
	while(environ[i])
	{
		for(i = 0; environ[i] != NULL; i++)
		{
			if(strstr(environ[i], pathname))
			{
				envp = environ[i];
				envp = _strncpy(envp, envp, 5);
				printf("%s\n", envp);
				return (envp);
			}
		}
	}
		return (NULL);
}
