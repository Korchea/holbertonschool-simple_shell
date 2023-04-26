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
 * 
 */

void function_call(char **tok, int *status)
{
	pid_t pid;
	
	char *_env[] = {_getenv("PATH"), NULL};
	
	if(execve(tok[0], tok, _env) == -1)
		{
			perror("Error");
		}
}
/**
 */ 
 

int main(int argc, char **argv, char *envp[])
{
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL, **tok = NULL;
    const char *taux = " \n";
    size_t size = 0;
    int i = 0, n_token = 0, line_error = 0, status;
	pid_t pid;
    
	while (1)
    {
		if (fork() == -1)
		{
			perror("Error:");
		}
		if (fork() > 0)
		{
			printf("$ ");
			line_error = getline(&cmd, &size, stdin);
			printf("%i\n", line_error);
			if (line_error == -1)
				break;
			wait(&status);
			if (WIFEXITED(status) == 0)
			{
				return (EXIT_FAILURE);
			}
		}
		else
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
		}
		if (tok != NULL)
			function_call(tok, &status);
    }
	if (tok != NULL)
	{
		for (i = 0; tok[i] && i <= n_token; i++)
			free(tok[i]);
		free(tok);
	}
    free(cmd);
    return (EXIT_SUCCESS);
}



/*isatty - Recurdame me tengo que marchar, recuerdame.*/
