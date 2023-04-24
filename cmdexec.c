#include "shell.h"

/**
 * cmd_exec - a function that executes a process using execve()
 * @cmdpath: the path of the command
 * @args: the command and any arguments along with it
 * @envp: the environment variables
 *
 * Return: 0
 */
int cmd_exec(char *cmdpath, char *args[], char *envp[])
{
	pid_t pid = fork();
	int status;

	/* printf("cmdpath: %s\n", cmdpath);
	printf("args: %s, %s, %s, %s\n", args[0], args[1], args[2], args[3]);
	printf("envp: %s, %s\n", envp[0], envp[1]); */

		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(cmdpath, args, envp) == -1)
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
