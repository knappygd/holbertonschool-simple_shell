#include "shell.h"

/**
 * main - spawns a prompt each time a command is executed.
 * it exits on a new line.
 * Return: 0 on success, otherwise -1
 */
int main(void)
{
	char *prompt = "$ ", *input = NULL, *cmd, *gtlc;
	size_t readline, len = 0;
	char **tkzr;
	char *args[2], *envp[2];

	while (1)
	{
		printf("%s", prompt);
		readline = getline(&input, &len, stdin);
		if (readline == -1)
		{
			break;
		}

		tkzr = tokenizer(input, _strlen(input));
		cmd = tkzr[0];
		gtlc = get_loc(cmd);

		if (cmd[0] == '/')
		{
			printf("shell: %s: Is a directory\n", cmd);
		}
		else
		{
			args[0] = cmd;
			args[1] = NULL;

			envp[0] = _getenv("PATH");
			envp[1] = NULL;

			cmd_exec(gtlc, args, envp);
		}

		for (int i = 0; tkzr[i] != NULL; i++)
		{
			free(tkzr[i]);
		}
		free(tkzr);
	}
	free(input);

	return (0);
}
