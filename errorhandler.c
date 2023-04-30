#include "shell.h"

/*
 * This file contains the err_constr(), responsible for constructing the
 * error message corresponding to its flag value, and printing it
 * with the appropriate failed commands or arguments.
 */

/**
 * err_constr - Construct an error message corresponding to a flag value.
 * @flag: The flag value corresponding to the error.
 * @exit: The exit value of the failed command.
 * @args: The command and its arguments, if any.
 * @shellname: The argv[0] value.
 *
 * Return: 0
 */
int err_constr(int flag, int exit, char **args, char *shellname)
{
	char *error = malloc(1024);
	char *cmd = args[0];

	exit = 1;

	if (flag == -1)
		sprintf(error, "%s: %d: %s: not found", shellname, exit, cmd);
	else if (flag == -7)
		sprintf(error, "%s: %d: %s: Illegal number: %s",
				shellname, exit, cmd, args[1]);
	else if (flag == -8)
	{
		sprintf(error, "%s: %d: %s: can't cd to %s", shellname, exit, cmd, args[1]);
	}

	fprintf(stderr, "%s\n", error);
	free(error);

	return (0);
}
