#include "shell.h"

/*
 * This file contains the entry function to execute the shell.
 * Here is the prompt spawn point and where input checks are made.
 * A full cycle consists of receiving input, tokenizing it,
 * getting the location of the command and passing the
 * required arguments to the function required to execute the command.
 * After the operation has been completed, the prompt spawns again;
 * in case it was unsuccessful, it may display the corresponding
 * error message.
 */

/**
 * main - Spawns a prompt to receive user input and performs the
 * required actions upon the input.
 * This is the shell entry function.
 *
 * Return: 0 if successful.
 */
int main(int argc, char *argv[])
{
	char *prompt = "$ ", *input = NULL, *path, *cmd;
	char *envp[] = {_getenv("PATH"), NULL}, **args;
	int ret = 0;
	size_t rl, len = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);

		rl = getline(&input, &len, stdin);
		if (rl == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		input[_strcspn(input, '\n')] = '\0';

		if (*input == '\0')
			continue;

		ret = input_flags(input, argv[0]);
	}
	free(input);

	return (ret);
}
