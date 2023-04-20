#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 */

extern char **environ;
char *_environ(char *envp);
char *_strncpy(char *dest, char *src, int n);
