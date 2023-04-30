#include "shell.h"

/**
 * _which - Looks for the path of a command.
 * @cmd: Is a command.
 * Return: The command with the directory.
 */
char *_which(const char *cmd)
{
	struct stat st;
	char *directory, *cmd_cpy = NULL;
	char *path = _getenv("PATH");

	if (path == NULL)
		return (NULL);
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
			return (fullpath);
		free(fullpath);
		directory = strtok(NULL, ":");
	}
	cmd_cpy = _strdup((char *)cmd);
	return (cmd_cpy);
}

/**
 * _strlen - Check the code.
 * Description: 'Returns the length of a string.'
 * @s: Is a string.
 * Return: Number of characters.
 */

unsigned int _strlen(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen(s + 1));
	}
	return (0);
}

/**
 * tokenizator - It count the number of tokens.
 * @token: Is the first token.
 * @n_token: Is the number of token.
 */

void tokenizator(char *token, int *n_token)
{
	*n_token = 0;
	while (token != NULL)
	{
		*n_token = *n_token + 1;
		token = strtok(NULL, " \n");
	}
	*n_token = *n_token + 1;
}

/**
 * _isatty - Look for the terminal.
 */

void _isatty(void)
{
	if (isatty(STDIN_FILENO) == 1)
		printf("$ ");
}

/**
 * main - Recreates a simple shell.
 * Return: If the function end well return success.
 */

int main(void)
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL, **tok = NULL;
	const char *taux = " \n";
	size_t size = 0;
	int i = 0, n_token = 0, line_error = 0, status;

	while (1)
	{
		_isatty();
		line_error = getline(&cmd, &size, stdin);
		fflush(stdin);
		if (line_error == -1 || strstr(cmd, "exit\n"))
			break;
		cmd_cpy = _strdup(cmd);
		token = strtok(cmd, taux);
		if (token == NULL)
		{
			free(cmd_cpy);
			continue;
		}
		tokenizator(token, &n_token);
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
		{
			function_call(tok, &status);
			for (i = 0; tok[i] && i <= n_token; i++)
				free(tok[i]);
			free(tok);
		}
	}
	free(cmd);
	return (EXIT_SUCCESS);
}
