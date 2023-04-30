#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
extern char **environ;

char *_strncpy(char *dest, char *src, int n)
{
	int i, j = 0;

	for (i = n; src[i] != '\0'; i++) 
    {
		dest[j] = src[i];
        j++;
	}
	dest[j] = '\0';
	return (dest);
}

/**
 * 
 */

char *_getenv(char *pathname)
{
	int i;
	char *envp;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strstr(environ[i], pathname))
		{
			envp = environ[i];
			envp = _strncpy(envp, envp, 5);
            return (envp);
		}
        
	}
	return (NULL);
}

int main(void)
{
	const char *separator = ":";
	char *_env = _getenv("PATH=");
	char *token = strtok(_env, separator);
	char *cmd = "ls";
    char *file = token;
	
    struct stat file_stats;
    int i, result = 0;

    for(i = 0; token != NULL; i++)
	{
			file = token;
			file = strcat(file, cmd);
			result = stat(file, &file_stats);

			token = strtok(NULL, separator);
	}
	if (result == -1)
        printf("File %s does not exist\n", file);
    else
    {
        printf("File %s exists", file);
    }
return(0);
}
