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
char *_getenv(char *pathname);
char *_strncpy(char *dest, char *src, int n);
void _witch(char **cmd);
void function_call(char **tok, int *status, char ***_env);
int main(void);