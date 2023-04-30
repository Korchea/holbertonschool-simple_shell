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

/*
 *
 */

char *_getenv(const char *name) {/*
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
*/	int i;
    char *env_value = NULL;

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(name, environ[i], strlen(name)) == 0)
        {
            env_value = strdup(&environ[i][strlen(name) + 1]);
            break;
        }
    }
    return (env_value);
}
/**
 *
 */

#include "shell.h"

char *_which(const char *cmd)
{
	struct stat st;
	char *directory;

	char *path = _getenv("PATH");
	if (path == NULL)
		return NULL;

	directory = strtok(path, ":");
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

		if (stat(fullpath, &st) == 0 && S_ISREG(st.st_mode))
			return fullpath;

		free(fullpath);
		directory = strtok(NULL, ":");
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
	char *full_path;

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
			if (strchr(tok[0], '/') != NULL)
				execve(tok[0], tok, _env);
			else
			{
				full_path = _which(tok[0]);
				if (full_path == NULL)
				{
					fprintf(stderr, "%s: command not found\n", tok[0]);
					exit(EXIT_FAILURE);
				}
				execve(full_path, tok, _env);
				perror(full_path);
				free(full_path);
				exit(EXIT_FAILURE);
			}
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