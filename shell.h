

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
char *_getenv(const char *name);
char *_strncpy(char *dest, char *src, int n);
char *_which(const char *cmd);
void function_call(char **tok, int *status);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void tokenizator(char *token, int* n_token);
void _isatty(void);
unsigned int _strlen(char *s);
int main(void);