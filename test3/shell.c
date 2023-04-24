#include "shell.h"
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
 */ 
 

int main(int argc, char **argv, char *envp[])
{
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL, **tok, *_env[] = {_getenv("PATH"), NULL};
    const char *taux = " \n";
    size_t size = 0;
    int i = 0, n_token = 0;
      
    while (printf("$ ") && getline(&cmd, &size, stdin) != -1)
    {
        cmd_cpy = strdup(cmd);
        token = strtok(cmd, taux);
        n_token = 0;
        while (token != NULL)
			{
				n_token++;
				token = strtok(NULL, taux);
			}
		n_token++;
        tok = malloc(sizeof(char *) * n_token);
        token = strtok(cmd_cpy, taux);
        for (i = 0; token != NULL; i++)
			{
				tok[i] = malloc(sizeof(char) * strlen(token));
				strcpy(tok[i], token);
				token = strtok(NULL, taux);
			}
        tok[i] = NULL;
        free(cmd_cpy);
        if (execve(tok[0], tok, _env) == -1)
        {
          perror("Error");
        }
        
        
    }
    free(cmd);
    return (EXIT_SUCCESS);
}
