#include "shell.h"

/**
 * cmd_exec - a function that executes a process using execve()
 * @arguments: the command and any arguments along with it
 *
 * Return: 1
 */
int cmd_exec(char **arguments)
{
	pid_t cpid;
	char *command = arguments[0];

	if (command[0] != '/' && command[0] != '.')
		command = get_loc(command);

	if (access(command, F_OK) == -1)
	{
		printf("no dir");
	}
	else
	{
		cpid = fork();
		if (cpid == -1)
		{
			printf("fork error");
			return (-1);
		}
		if (cpid == 0)
		{
			execve(command, arguments, environ);
		}
	}

	return (0);
}
