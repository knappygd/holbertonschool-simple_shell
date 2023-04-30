#include "shell.h"

/*
 * This file contains the input_flags() and handle() functions,
 * responsible for determining what to do with the user input.
 * input_flags() analyzes the input and assign a value to a flag based on it.
 * The flag value is then passed to handle(),
 * that will determine what to do depending on the flag value.
 * Lastly, handle() will attempt to do the required task,
 * or return a new flag value if it was unsuccessful in doing so,
 * and raise any corresponding error messages.
 *
 * SUCCESS FLAG CODES:
 * 1: Command found and is executable
 * 2: Command found and is built-in
 *
 * FAILURE FLAG CODES:
 * -1: Command not found (neither executable nor built-in)
 * -2: A directory was input instead of a command and is NOT an executable path
 * -3: Tokenization unsuccessful
 * -4: fork() failure
 * -5: execve() failure
 * -6: waitpid() failure
 * -7: exit status negative or NaN
 * -8: cd failure
 */

/**
 * input_flags - A function that assigns flag values based on the input.
 * @input: The user input throung the shell prompt.
 * @shellname: The argv[0] value.
 *
 * Return: The flag containing its value.
 */
int input_flags(char *input, char *shellname)
{
	int i, is_b, handle_ret = 0, flag = 0;
	char *cmd, **args, *path;

	args = tokenizer(input);
	if (!args)
		flag = -3;

	cmd = args[0];

	is_b = is_builtin(cmd);

	if (is_b > 0)
	{
		flag = 2;
		handle_ret = handle(flag, NULL, args, shellname, is_b);
	}
	else
	{
		if (cmd[0] == '/')
			path = cmd;
		else
			path = get_loc(cmd);

		if (!path)
			flag = -1;
		else
			flag = 1;

		handle_ret = handle(flag, path, args, shellname, 0);

		if (cmd[0] != '/')
		{
			free(path);
		}
	}

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	free(args);

	return (handle_ret);
}

/**
 * handle - Decides what to do based on the input_flags return.
 * @flag: The flag value to work with.
 * @path: The command path.
 * @args: The command and its arguments, if any.
 * @envp: The environ values.
 * @shn: The argv[0] value.
 * @i: The index of the built-in commands.
 *
 * Return: The exit value (0 if successful, 1 if not).
 */
int handle(int flag, char *path, char **args, char *shn, int i)
{
	int exit = 0;

	if (flag > 0)
	{
		switch (flag)
		{
		case 1:
			exit = cmd_exec(path, args);
			break;
		case 2:
			exit = builtin_handler(args, shn, i);
			break;
		default:
			break;
		}
	}
	else if (flag < 0)
	{
		switch (flag)
		{
		case -1:
			exit = 127;
			err_constr(-1, exit, args, shn);
			break;
		case -2:
			printf("is directory");
			break;
		case -3:
			printf("failed to tokenize");
			break;
		default:
			break;
		}
	}
	return (exit);
}
