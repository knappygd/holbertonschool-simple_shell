#include "shell.h"

/*
 * This file contains the get_loc() function, responsible
 * for locating the executable file of the command received.
 * This allows the user to be able to only type the command name
 * instead of having to pass the path to the excutable.
 */

/**
 * get_loc - Locates the executable file of a command
 * and return the path to it if found.
 * @command: The command to which attempt to locate the executable for.
 *
 * Return: Path to the executable.
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

			if (stat(filepath, &buf) == 0)
			{
				free(path);
				free(aux_path);
				return (filepath);
			}
			else
			{
				free(filepath);
				filepath = NULL;
				token = strtok(NULL, ":");
			}
		}
		free(aux_path);
		free(path);
	}

	if (stat(command, &buf) == 0)
		return (command);

	return (NULL);
}
