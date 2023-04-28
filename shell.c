#include "shell.h"

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

