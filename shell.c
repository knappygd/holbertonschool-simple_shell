#include "shell.h"

/**
 * main - spawns a prompt each time a command is executed.
 * it exits on a new line.
 * Return: 0 on success, otherwise -1
 */
int main(void)
{
	char *prompt = "$ ", *input = NULL, *cmd, *cmdpath;
	size_t readline, len = 0;
	char **tokens;
	char *args[2], *envp[2];

	while (1)
	{
		printf("%s", prompt);
		readline = getline(&input, &len, stdin);
		if (readline == -1)
		{
			break;
		}

		tokens = tokenizer(input, _strlen(input));
		cmd = tokens[0];
		cmdpath = get_loc(cmd);

		if (cmd[0] == '/')
		{
			printf("shell: %s: Is a directory\n", cmd);
		}
		else
		{
			envp[0] = _getenv("PATH");
			envp[1] = NULL;

			cmd_exec(cmdpath, tokens, envp);
		}

		for (int i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
		free(cmdpath);
	}
	free(input);

	return (0);
}
