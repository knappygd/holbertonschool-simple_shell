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
 * 1: Command found
 *
 * FAILURE FLAG CODES:
 * -1: Command not found (neither executable nor built-in)
 * -2: A directory was input instead of a command and is NOT an executable path
 * -3: Tokenization unsuccessful
 * -4: fork() failure
 * -5: execve() failure
 * -6: waitpid() failure
 */

/**
 * input_flags - A function that assigns flag values based on the input.
 * @input: The user input throung the shell prompt.
 *
 * Return: The flag containing its value.
 */
int input_flags(char *input, char *shellname)
{
	int i, handle_ret = 0, len = _strlen(input) + 1, flag = 0;
	char *cmd, **args, *path;
	char *envp[] = {_getenv("PATH"), NULL};

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

	handle_ret = handle(flag, path, args, envp, shellname);

	for (int i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	free(path);

	/* printf("%d", flag); */

	return (handle_ret);
}

int handle(int flag, char *path, char **args, char *envp[], char *shellname)
{
	char *error_msg;
	int exit = 0;

	/* Handle success flags */
	if (flag > 0)
	{
		switch (flag)
		{
		case 1:
			exit = cmd_exec(path, args, envp);
			break;
		default:
			break;
		}
	}
	/* Handle failure flags */
	else if (flag < 0)
	{
		switch (flag)
		{
		case -1:
			exit = 1;
			error_msg = err_constr(-1, exit, args[0], shellname);
			printf("%s\n", error_msg);
			free(error_msg);
			break;
		case -2:
			printf("is directory");
			break;
		case -3:
			("failed to tokenize");
			break;
		default:
			break;
		}
	}

	return (exit);
}

/*
other things to do is fix mv, make more builtin funcs and echo $? outputs 0
all the time, even after misusing a command, where it should be 1.
*/