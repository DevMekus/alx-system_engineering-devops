#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int infinite_while(void);

/**
 * main - Function Creates five zombie processes.
 *
 * Return: 0 on Success.
 */

int main(void)
{
	pid_t process_id;
	char counter = 0;

	while (counter < 5)
	{
		process_id = fork();
		if (process_id > 0)
		{
			printf("Zombie process created, process_id: %d\n", process_id);
			sleep(1);
			counter++;
		}
		else
			exit(0);
	}

	infinite_while();

	return (EXIT_SUCCESS);
}

/**
 * infinite_while - Run an infinite while loop.
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}
