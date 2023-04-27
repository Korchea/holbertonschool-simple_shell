#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>

extern char **environ;
char *_getenv(char *pathname);
char *_strncpy(char *dest, char *src, int n);
char *_witch(char *cmd);
int main(int argc, char **argv, char *envp[]);