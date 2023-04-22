#include "shell.h"

/**
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
int main(void)
{
	char *prompt = "$ ", *input = NULL, *cmd, *path, *envp[2], **args;
	size_t readline, len = 0;

	while (1)
	{
		printf("%s", prompt);
		readline = getline(&input, &len, stdin);
		if (readline == -1)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "") == 0)
		{
			continue;
		}

		args = tokenizer(input, readline);
		cmd = args[0];
		path = get_loc(cmd);

		if (cmd[0] == '/')
		{
			printf("shell: %s: Is a directory\n", cmd);
		}
		else
		{
			envp[0] = _getenv("PATH");
			envp[1] = NULL;

			cmd_exec(path, args, envp);
		}

		for (int i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		free(path);
	}
	free(input);

	return (0);
}
