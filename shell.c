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
 * @argc: (unused)
 * @argv: Used for obtaining the shell name/path.
 *
 * Return: 0 if successful.
 */
int main(int argc, char *argv[])
{
	char *prompt = "$ ", *input = NULL;
	int ret = 0, i;
	size_t rl, len = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);

		rl = getline(&input, &len, stdin);
		if (rl == (size_t)-1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		if (*input == '\n')
			continue;

		i = space_input(input);

		if (i > 0)
			continue;

		ret = input_flags(input, argv[0]);
		if (ret == -5)
		{
			free(input);
			exit(0);
		}
	}
	free(input);
	exit(ret);
	return (ret);
}

/**
 * space_input - Auxiliary function to check for space input.
 * @input: The user input to check.
 *
 * Return: A flag indicating the input content.
 */
int space_input(char *input)
{
	int i, in_len = _strlen(input);

	for (i = 0; i < in_len; i++)
	{
		if (input[i] != ' ')
		{
			if (input[i] == 10)
				break;
			i = 0;
			break;
		}
	}

	return (i);
}
