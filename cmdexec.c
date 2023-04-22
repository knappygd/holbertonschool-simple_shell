#include "shell.h"

/**
 * This file contains the cmd_exec() function, responsible for
 * executing the command and any arguments it may have.
 * It forks a pre-existing process and assigns the forked process,
 * the child, a new execution.
 * It makes use of the execve() and fork() functions.
 */

/**
 * cmd_exec - Executes a command and any arguments by forking a process
 * and changing its execution.
 * @gtlc: The path of the command executable file or built-in function.
 * @args: The command and any arguments along with it.
 * @envp: The environment variables.
 *
 * Return: 0 if successful.
 */
int cmd_exec(char *gtlc, char *args[], char *envp[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(gtlc, args, envp) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}

	return (0);
}
