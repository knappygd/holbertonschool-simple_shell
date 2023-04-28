#include "shell.h"
/*
 * This file contains builtin_handler(), responsible for managing a
 * built-in command input.
 * Depending on the built-in command index, it will execute the
 * corresponding one.
 *
 * 1: cd
 * 2: exit
 * 3: env
*/

/**
 * builtin_handler - Decides what command to execute based on its index.
 * @args: The command arguments array.
 * @shellname: The argv[0] string.
 * @index: The command index.
 *
 * Return: The exit value (0 if successful, 1 if not).
*/
int builtin_handler(char **args, char *shellname, int index)
{
	int exit = 0;

	switch (index)
	{
	case 1:
		if (!args[1])
			exit = change_dir(_getenv("HOME"));
		else
			exit = change_dir(args[1]);
		if (exit == 1)
			err_constr(-8, exit, args, shellname);
		break;
	case 2:
		if (args[1])
		{
			if (atoi4exit(args[1]) == -1)
			{
				exit = 1;
				err_constr(-7, exit, args, shellname);
			}
		}
		else
		{
			exit = exit_sh();
		}
		break;
	case 3:
		exit = print_env();
		break;
	default:
		break;
	}

	return (exit);
}

/**
 * is_builtin - Checks if the command passed is a built-in command.
 * @cmd: The command to check.
 *
 * Return: The index of the command, or -1 if the command is not a built-in.
*/
int is_builtin(char *cmd)
{
	char *builtin_arr[] = {"cd", "exit", "env", NULL};
	int i;

	for (i = 0; builtin_arr[i]; i++)
		if (_strcmp(cmd, builtin_arr[i]) == 0)
			return (i + 1);

	return (-1);
}
