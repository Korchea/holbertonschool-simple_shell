#include <stdio.h>
/**
 *
 */
int main(int ac __attribute__((unused)), char **av)
{
	int i;

	for(i = 0; av[i] != NULL; i++)
	{
		printf("%s ", av[i]);
	}
	printf("\n");
	return(0);
}
