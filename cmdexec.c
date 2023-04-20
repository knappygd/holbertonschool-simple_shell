#include "shell.h"

/**
 * cmd_exec - a function that executes a process using execve()
 * @gtlc: the path of the command
 * @args: the command and any arguments along with it
 * @envp: the environment variables
 *
 * Return: 0
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
