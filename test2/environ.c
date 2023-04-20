#include "main.h"
#include <string.h>
/**
 *
 */
int main()
{
	int i;
	char *pathname = "PATH=";
	char *separator = " ";
	char *token;

	token = strtok(pathname, separator);
	while(environ[i])
	{
		for(i = 0; environ[i] != NULL; i++)
		{
			if(strstr(environ[i], pathname))
			{
				printf ("%s\n", environ[i]);
			}
		}
	}
		return (0);
}
