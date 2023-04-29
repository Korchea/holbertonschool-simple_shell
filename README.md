# Simple Shell

In this function we replicate a simple command interpretor. It must resive a command, options and directions, then look it is valid, it looks for the direction of the command anthe options, if it is valid it run the command like a normal shell should do.

We can call the commands in different forms, those are using the command echo with the command in double quotation marks and two ampersant whit the executable of the shell, or we can use the executable and wait to the call of he function to write the command.

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

In this project we use (((PONER NUMERO))) functions, those functions are main, _getenv, _strlen, _strncpy and function_call.
- `int main(void)`: It is our principal function, here we don't recive enything. When the program runs, it prints a `$` to the terminal, at which point this function receives a string given from the imput, he tokenize it and then sends it to the function function_call.
- `void function_call(char **tok, int *status)`: This function creates a second process, a child process, in this process we execute the command that we have written in the main function.
- `char *_getenv(char *pathname)`: In this function we look for information in the environment, in case we look for the path, when we get the path we call the strncpy function to cut the function and return the path in string format.
- `char *_strncpy(char *dest, char *src, int n)`: In this we receive two strings and an integer "n", we stop at position "n" of the second string and copy each character of the second string into string 1 from "n".
- `char *_strcpy(char *dest, char *src)`: This is a normal strcpy function, this function simply copies the contents of one string to another string.
- `char *_strdup(char *str)`: This is a normal strdup function, it takes a string and duplicates it with a memory call.
- `unsigned int _strlen(char *s)`: In this function we return the length of a string.

### Different cases of the shell:
```
echo "/bin/ls" | ./hsh
README.md  functions.c  hsh  shell.c  shell.h
```
```
echo "/bin/ls -l" | ./hsh
total 72
-rw-r--r-- 1 root root  2872 Apr 29 16:07 README.md
-rw-r--r-- 1 root root  2036 Apr 29 16:07 functions.c
-rwxr-xr-x 1 root root 17632 Apr 29 16:07 hsh
-rw-r--r-- 1 root root  2446 Apr 29 16:07 shell.c
-rw-r--r-- 1 root root   514 Apr 29 16:07 shell.h
```
```
echo "/bin/pwd" | ./hsh
/root/Dev/holbertonschool-simple_shell
```
```
echo "/bin/hello" | ./hsh
/bin/hello: No such file or directory
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