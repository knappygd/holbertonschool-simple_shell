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
int cmd_exec(char *input)
{
	pid_t pid = fork();
	int status, flag, len = _strlen(input) + 1;
	char *cmd, **args, *path;
	char *envp[] = {_getenv("PATH"), NULL};

	if (pid == -1)
	{
		perror("fork");
		flag = -4;
	}
	else if (pid == 0)
	{
		args = tokenizer(input, len);
		if (!args)
			flag = -3;

		cmd = args[0];

		/* Before calling get_loc it should check if it is a built-in */
		path = get_loc(cmd);
		if (!path)
			flag = -1;
		else
			flag = 1;

		printf("path: %s\n", path);
		for (int j = 0; args[j]; j++)
			printf("args[%d]: %s\n", j, args[j]);

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
	}

	return (flag);
}
