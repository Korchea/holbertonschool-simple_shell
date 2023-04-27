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
<<<<<<< HEAD
int main(int argc, char **argv, char *envp[]);
=======
char *_witch(char *cmd);
int main(int argc, char **argv, char *envp[]);
>>>>>>> d1920276f948abf0ec582bb9b2d99d834eb88427
