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
    char *cmd = NULL, *token = NULL, *tok[3] = {}, *env_aux = NULL, *_env[2];
    const char *taux = " ";
    size_t size = 0;
    int i = 0, r, b;
      
    _env[0] = _getenv("PATH");
    _env[1] = NULL;
    while (1)
    {   
        printf("$ ");
        b = getline(&cmd, &size, stdin);
        if (b == -1)
        {
            free(cmd);
            return (-1);
        }
         
        token = strtok(cmd, taux);
        i = 0;
        while (token != NULL)
        {
            tok[i] = token;
            token = strtok(NULL, taux);
            i++;
        }
        
        tok[i] = NULL;
        r = execve(tok[0], tok, _env);
         if (r == -1)
        {
          perror("Error");
        } 
    }
    free(cmd);
    return (0);
}
