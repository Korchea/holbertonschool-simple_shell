# Simple Shell

In this function we replicate a simple command interpretor. It must receive a command, options and directions, then look it is valid, it looks for the direction of the command and the options, if it is valid it run the command like a normal shell should do.

We can call the commands in different forms, those are using the command echo with the command in double quotation marks and two ampersand with the executable of the shell, or we can use the executable and wait to the call of he function to write the command.

## Command form
The first form: 
```
$ echo "/bin/ls" | ./hsh
```
The second form: 
```
$ ./hsh
($) /bin/ls
```

In this project we use 11 functions, those functions are main, _getenv, _strlen, _strncpy, _which, tokenizator, _isatty, _strcpy, _strdup, print_env and function_call.
- `int main(void)`: It is our main function, here we receive nothing. When the program runs, it prints a `$` to the terminal, at which point this function receives a string given by input, tokenizes it, and then sends it to function_call.
- `char *_which(const char *cmd)`: This function looks up the directory of the command.
- `void tokenizator(char *token, int *n_token)`: This function counts the number of tokens in the input string.
- `void _isatty(void)`: This function searches the terminal.
- `void function_call(char **tok, int *status)`: This function creates a second process, a child process, in this process we call the _which function and execute the command that we have written in the main function.
- `char *_getenv(const char *name)`: In this function we look for information in the environment, in case we look for the path, when we get the path we call the strncpy function to cut the function and return the path in string format.
- `char *_strncpy(char *dest, char *src, int n)`: In this we receive two strings and an integer "n", stop at position "n" of the second string, and copy each character from the second string into string 1 from "n".
- `char *_strcpy(char *dest, char *src)`: This is a normal strcpy function, this function simply copies the contents of one string to another string.
- `char *_strdup(char *str)`: This is a normal strdup function, it takes a string and duplicates it with a memory call.
- `unsigned int _strlen(char *s)`: In this function we return the length of a string.
- `void print_env(void)`: This function prints the current enviroment.

### Different cases of the shell:
```
echo "/bin/ls" | ./hsh
AUTHORS  README.md  functions.c  functions2.c  hsh  shell.c  shell.h
```
```
echo "ls" | ./hsh
AUTHORS  README.md  functions.c  functions2.c  hsh  shell.c  shell.h
```
```
echo "/bin/ls -l" | ./hsh
total 56
-rw-r--r-- 1 root root   142 Apr 29 18:55 AUTHORS
-rw-r--r-- 1 root root  4224 Apr 30 22:49 README.md
-rw-r--r-- 1 root root  1723 Apr 30 22:50 functions.c
-rw-r--r-- 1 root root  1051 Apr 30 22:51 functions2.c
-rwxr-xr-x 1 root root 27120 Apr 30 22:51 hsh
-rw-r--r-- 1 root root  2449 Apr 30 16:44 shell.c
-rw-r--r-- 1 root root   611 Apr 30 22:38 shell.h
```
```
echo "ls -l" | ./hsh
total 56
-rw-r--r-- 1 root root   142 Apr 29 18:55 AUTHORS
-rw-r--r-- 1 root root  4224 Apr 30 22:49 README.md
-rw-r--r-- 1 root root  1723 Apr 30 22:50 functions.c
-rw-r--r-- 1 root root  1051 Apr 30 22:51 functions2.c
-rwxr-xr-x 1 root root 27120 Apr 30 22:51 hsh
-rw-r--r-- 1 root root  2449 Apr 30 16:44 shell.c
-rw-r--r-- 1 root root   611 Apr 30 22:38 shell.h
```
```
echo "/bin/pwd" | ./hsh
/root/Dev/holbertonschool-simple_shell
```
```
echo "pwd" | ./hsh
/root/Dev/holbertonschool-simple_shell
```
```
echo "/bin/hello" | ./hsh
/bin/hello: No such file or directory
```
```
echo "exit" | ./hsh
```
```
echo "    " | ./hsh
```

### To use that function we need to:
- Clone the repository.
- Compile all with the command `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`.
- You can call the function writing `./hsh` in the terminal.
- Then you have to use it calling the command with the diretory like "/bin/ls", don't forget to enjoy.

#### If you need some help you can ask to the creators: 
- 6319@holbertonstudents.com GitHub: [Nacho228](https://github.com/Nacho228)
- 6334@holbertonstudents.com GitHub: [Korchea](https://github.com/Korchea)

#### Autors:
- Ignacio Llanes - Holberton School Montevideo, Cohort 20.
- Guillermo Vega - Holberton School Montevideo, Cohort 20.
