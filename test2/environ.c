#include "main.h"
#include <string.h>
/**
 */

char **_getenv(char *envp)
{
	int i;
	char *pathname = "PATH=";
	/*char *separator = " ";
	char *token;

	token = strtok(pathname, separator);*/
	while(environ[i])
	{
		for(i = 0; environ[i] != NULL; i++)
		{
			if(strstr(environ[i], pathname))
			{
				return (&environ[i]);
				/*envp = environ[i];
				envp = _strncpy(envp, envp, 5);
				printf("PATH : %s\n", envp);
				printf("PATH : %s\n", env);
				return (envp);*/
			}
		}
	}
		return (NULL);
}
