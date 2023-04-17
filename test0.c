#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
 
int main()
{
	int i;

	for (i = 0; i < 10000; i++)
	{
    if (fork()== 0)
        exit(0);           /* terminate child */
    else
        wait(NULL);  /*reaping parent */
	}
    printf("Parent pid = %d\n", getpid());
    return 0;
}
