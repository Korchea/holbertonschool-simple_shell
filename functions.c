#include "shell.h"

/**
 * _strncpy - Check the code.
 * Description: 'Copies a string.'
 * @dest: is a string.
 * @src: is a string.
 * @n: is an int.
 * Return: dest.
 */

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

/**
 * 
 */

void function_call(char **tok, int *status)
{
	pid_t pid;
	char *_env[2];
	
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		_env[0] = _getenv("PATH");
		_env[1] = NULL;
		execve(tok[0], tok, _env);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(status);
	}
}