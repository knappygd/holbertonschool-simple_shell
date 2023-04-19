#include "shell.h"

/**
 * get_loc - locate the executable file of a command and return the path
 * @command: the command to which attempt to locate the executable for
 *
 * Return: the path to the executable
 */
char *get_loc(char *command)
{
	int dirlen, cmdlen = _strlen(command);
	char *path, *aux_path, *token, *filepath;
	struct stat buf;

	path = _strdup(_getenv("PATH"));

	if (path)
	{
		aux_path = _strdup(path);
		token = strtok(aux_path, ":");
		while (token)
		{
			dirlen = _strlen(token);
			filepath = malloc(cmdlen + dirlen + 2);

			_strcpy(filepath, token);
			_strcat(filepath, "/");
			_strcat(filepath, command);
			_strcat(filepath, "\0");

			if (stat(filepath, &buf) == 0)
			{
				free(aux_path);
				return (filepath);
			}
			else
			{
				free(filepath);
				token = strtok(NULL, ":");
			}
			free(aux_path);

			if (stat(command, &buf) == 0)
				return (command);
			return (NULL);
		}
		return (NULL);
	}
}
