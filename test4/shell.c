#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
#include <errno.h>
extern char **environ;

/*
char *which(const char *cmd)
{
	char *path = _getenv("PATH");
	if (path == NULL)
		return NULL;

	char *directory = strtok(path, ":");
	while (directory != NULL)
	{
		char *fullpath = malloc(strlen(directory) + strlen(cmd) + 2);
		if (fullpath == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}

		strcpy(fullpath, directory);
		strcat(fullpath, "/");
		strcat(fullpath, cmd);

		struct stat st;
		if (stat(fullpath, &st) == 0 && S_ISREG(st.st_mode))
			return fullpath;

		free(fullpath);
		directory = strtok(NULL, ":");
	}

	return (NULL);
}

void _witch(char **cmd)
 {
	 char *path = _getenv("PATH"), *directory = NULL, *fullpath = NULL;

	 directory = strtok(path, ":");

	 while (directory)
	 {
		 fullpath = malloc(sizeof(char) * (strlen(directory) + strlen(*cmd) + 2));
		 if (fullpath == NULL)
			exit(EXIT_FAIL)
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

/*
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
		if (tok[0] != NULL) 
		{
		execve(tok[0], tok, _env);
		perror(tok[0]);
		exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(status);
	}
}

/**
 * _strcpy - Check the code.
 * Descriprion: 'Copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.'
 * @dest: is a string.
 * @src: is a string.
 * Return: the pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (i >= 0)
	{
		*(dest + i) = *(src + i);
		if (*(src + i) == '\0')
		{
			break;
		}
		i++;
	}
	return (dest);
}

/**
 * _strdup - Check the code.
 * Description: 'Returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as  parameter.'
 * @str: Is a string.
 * Return: NULL if str = NULL or if insufficient memory was availble,
 * else a pointer to the duplicate string.
 */

char *_strdup(char *str)
{
	int i, k;
	char *j;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		j = malloc(sizeof(char) * (i + 1));
		if (j == NULL)
		{
			exit(1);
		}
		for (k = 0; k < i + 1; k++)
		{
			j[k] = str[k];
		}
		return (j);
	}
}

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
		cmd_cpy = _strdup(cmd);
		token = strtok(cmd, taux);
		if (token == NULL)
		{
			free(cmd_cpy);
			continue;
		}
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
			tok[i] = malloc(sizeof(char) * (strlen(token) + 1));
			_strcpy(tok[i], token);
			token = strtok(NULL, taux);
		}
		tok[i] = NULL;
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
