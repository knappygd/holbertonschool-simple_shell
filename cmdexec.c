#include "shell.h"

/*
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
int cmd_exec(char *path, char **args, char *envp[])
{
	pid_t pid = fork();
	int status, flag = 0;

	if (pid == -1)
	{
		perror("fork");
		flag = -4;
	}
	else if (pid == 0)
	{
		if (execve(path, args, envp) == -1)
		{
			perror("execve");
			flag = -5;
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			flag = -6;
		}

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (flag);
}
