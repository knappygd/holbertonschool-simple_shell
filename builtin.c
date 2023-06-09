#include "shell.h"

/*
 * This file contains the function implementations
 * required to execute built-in commands.
 * These are commands built into the shell itself,
 * unlike commands such as `ls` or `echo`, which are
 * executables.
 *
 * The built-ins included in this shell are:
 * - cd: Changes to a newly specified working directory
 * - exit: Exits the shell interface
 */

/**
 * change_dir - Changes to a newly specified working directory,
 * using the chdir() function.
 * @dir: A pointer to the directory to change.
 *
 * Return: The return value of the chdir() function.
 */
int change_dir(char *dir)
{
	int ret;

	if (!dir)
		dir = _getenv("HOME");

	if (_strcmp(dir, "-") == 0)
		dir = _getenv("OLDPWD");

	ret = chdir(dir);

	if (ret == -1)
	{
		ret = 1;
	}
	return (ret);
}

/**
 * exit_sh - Exits the shell. If no argument is passed, it exits with 0.
 * Otherwise, it converts the argument to an int and exits with that number.
 *
 * Return: A code to signal exit.
 */
int exit_sh(void)
{
	return (-5);
}

/**
 * print_env - Prints the contents of the environ variable in newlines.
 *
 * Return: 0
 */
int print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

	return (0);
}
