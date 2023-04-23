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
int input_flags(char *input)
{
	int i, len = _strlen(input) + 1, flag = 0;
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

	for (int i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	free(path);

	/* printf("%d", flag); */

	return (flag);
}

int handle(char *input, char *shellname)
{
	int flag = input_flags(input), len = _strlen(input) + 1;
	char *error_msg;

	/* Handle success flags */
	if (flag > 0)
	{
		switch (flag)
		{
		case 1:
			cmd_exec(input);
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
			/* args = tokenizer(input, len);
			if (!args)
				flag = -3; */
			/* error_msg = err_constr(-1, args[0], shellname); */
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

	return (0);
}

/*
The thing to fix is that to print the error message
i need to pass the command name to err_constr, which is args[0].
however args is the tokenizer, and is already called in flag_raiser.
calling tokenizer again in handler fucks up the args.
the solution would be to pass args to handler but what do i do in shell.c lol.
the other approach is to make an extra function to call handle from shell.c,
which only takes input and passes it to handle.
anyway that's to fix.
other things to do is fix mv, make more builtin funcs and echo $? outputs 0
all the time, even after misusing a command, where it should be 1.
*/