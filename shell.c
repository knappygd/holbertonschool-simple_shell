#include "shell.h"

/**
 * main - spawns a prompt each time a command is executed.
 * 		 it exits on a new line.
 * Return: 0 on success, otherwise -1
 */
int main()
{
	char *prompt = "$ ";
	char *input = NULL;
	size_t len = 0;
	size_t readline;
	char **args;

	while (1)
	{
		printf("%s", prompt);
		readline = getline(&input, &len, stdin);
		if (readline == -1)
			return (-1);

		if (input[0] == '\n')
			printf("hey");

		cmd_exec(args);
	}
}
