# Simple Shell

In this function we replicate a simple command interpretor. It must resive a command, options and directions, then look it is valid, it looks for the direction of the command anthe options, if it is valid it run the command like a normal shell should do.

We can call the commands in different forms, those are using the command echo with the command in (((COMILLAS))) and two ampersant whit the executable of the shell, or we can use the executable and wait to the call of he function to write the command.

## Command form
The first form: 
```
$ echo "/bin/ls" | ./hsh
```
The second form: 
```$ ./hsh
($) /bin/ls
```
| Conversion specifier | Description					|
|-----|:---------------------------------------------------------------|
| `%c` | It represent a variable of type char.				|
| `%s` | It represent a variable of type `char *`, commonly called string. |
| `%%` | It is used to remplace it with a '%'.				|
| `%d` | It represent a variable of type int in decimal.		|
| `%i` | It represent a variable of type int.				|

In this project we use (((PONER NUMERO))) functions, those functions are main, _getenv, _strlen, _strncpy and function_call.
- `int main(int argc, char **argv, char *envp[])`: It is our principal function, here we don't recive enything(((((ME QUEDE ACA))))). This function creates the list of the variables given in the ellipsis, traverses the string format, look for the conversion specifiers and prints the string format, if it recognise a % in format it call the functon get_format and it returns the number of characters printed.
- `void get_format(const char *format, va_list ap, int i, int *count)`: This function create a structure of chars and functions, look up for the conversion specifiers in the structure and if it find something it call to other function, those functions are casechar, casestring, casepercent and caseint.
- `int casechar(va_list ap)`: In this function we print the char who is in the list and return 1 who is the number of prints.
- `int casestring(va_list ap)`: In this function we print the string who is in the list and return the length of the string using the function _strlen.
- `int casepercent(va_list ap __attribute__((unused)))`: In this function we print the char '%' and return 1 who is the number of prints, we use the attribute unused because we make all the functions of the structure with the same format and we don´t use the list.
- `int caseint(va_list ap)`: In this function we recive an int from the list and send it to the function print_int, it returns the number of digits of the int.
- `void print_int(long int n, int *count)`: In this function we print the integer and if it is less than 0 first print a '-'.
- `unsigned int _strlen(char *s)`: In this function we return the length of a string.

### Different limit cases of the function:
```
Input:
_printf(NULL);
Output:
```
```
Input:
_printf("Let´s try to printf a simple sentence.");
Output:
Let´s try to printf a simple sentence.
```
```
Input:
_printf("%D\n", INT_MIN);
Output:
-2147483648
```
```
Input:
_printf("Hi, %s\n", "Betty");
Output:
Hi, Betty
```
```
Input:
_printf("If you %s\n", NULL);
Output:
If you (null)
```
```
Input:
_printf("This is a char %c\n", 'H');
Output:
This is a char H
```
```
Input:
_printf("%% % \n");
Output:
% %
```

### To use that function we need to:
- Clone the repository.
- Compile all with the command `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`.
- You can call the function writing `./hsh` in the terminal.
- Then you have to use it like a normal shell, don't forget to enjoy.

#### If you need some help you can ask to the creators: 
- 6319@holbertonstudents.com GitHub: [Nacho228](https://github.com/Nacho228)
- 6334@holbertonstudents.com GitHub: [Korchea](https://github.com/Korchea)

#### Autors:
- Ignacio Llanes - Holberton School Montevideo, Cohort 20.
- Guillermo Vega - Holberton School Montevideo, Cohort 20.