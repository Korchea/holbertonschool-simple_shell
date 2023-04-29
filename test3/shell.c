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

<<<<<<< HEAD
	directory = strtok(path, ":");
	printf("path = %s\n", path);
	while (directory)
	{
		fullpath = malloc(sizeof(char) * (strlen(directory) + strlen(cmd) + 2));
		if (fullpath == NULL)
		{
			EXIT_FAILURE;
		}
		strcpy(fullpath, directory);
		strcat(fullpath, "/");
		strcat(fullpath, cmd);
		/* printf("%s", fullpath); */
		/* stat_value = stat(fullpath, &st);

		 strcpy(fullpath, directory);
		 strcat(fullpath, "/");
		 strcat(fullpath, *cmd);
		 printf("%s", fullpath);
		 struct stat st = {0};
		 if (stat(fullpath, &st) == 0 && S_ISREG(st.st_mode))
		 {
			 printf("%s\n", *cmd);
			 free(path);
			 *cmd = malloc(sizeof(char) * strlen(fullpath) + 1);
			 strcpy(*cmd, fullpath);
			 break;
		 }
		 else
		 {
			 directory = strtok(NULL, ":");
		 }
		 printf("stat returned %d, errno = %d\n", stat(fullpath, &st), errno);
	 }
	 if (fullpath != NULL)
	 {
	 	free(fullpath);
	 }
 }
*/ 
=======
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

/**
 */ 
 
>>>>>>> d9c8ed0a9a6f4a25df7c1cb6247d2c911bf9e521

int main(void)
{
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL, **tok = NULL;
    const char *taux = " \n";
    size_t size = 0;
    int i = 0, n_token = 0, line_error = 0, status;
    
    while (1)
    {
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		line_error = getline(&cmd, &size, stdin);
		fflush(stdin);
		if (line_error == -1)
				break;
<<<<<<< HEAD
		//cmd = which(cmd);
		//_witch(&cmd);
=======
>>>>>>> 28d8fc678909c35d3b4825119c328c3d07fca5a7
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
        if(cmd_cpy != NULL)
			free(cmd_cpy);
		if (tok != NULL)
			function_call(tok, &status);
		if (tok != NULL)
	{
		
		for (i = 0; tok[i] && i <= n_token; i++)
			free(tok[i]);
		free(tok);
	}
    }
	
    free(cmd);
    return (EXIT_SUCCESS);
}



/*isatty - Recurdame me tengo que marchar, recuerdame.*/