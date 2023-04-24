#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
extern char **environ;

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

int main(int argc, char **argv, char **envp)
{
    char *cmd = NULL, *taux = " ", *token = NULL, *tok[8] = {}, *env_aux = NULL, *_env[8] = {};
    size_t size = 0;
    int i = 0, j = 0;

    env_aux = strtok(_getenv("PATH"), ":");
        while (env_aux != NULL)
        {
            _env[j] = env_aux;
            env_aux = strtok(NULL, ":");
            j++;
        }
        _env[j] = "\0";
    while (printf("$ ") && getline(&cmd, &size, stdin) != -1)
    {
        token = strtok(cmd, taux);
        i = 0;
        while (token != NULL)
        {
            tok[i] = token;
            /*printf("%s\n", tok[i]);*/
            token = strtok(NULL, taux);
            i++;
        }
        for (; j >= 0; j--)
        {
            if (strstr(tok[0], _env[j]))
            {
                tok[0] = _strncpy(tok[0], tok[0], strlen(_env[j]));
            }
        }
        tok[i] = "\0";
        execve(tok[0], tok, _env);
    }
    free(cmd);
    return (0);
}