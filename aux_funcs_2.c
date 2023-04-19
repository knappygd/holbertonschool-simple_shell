#include "shell.h"

/**
 * _strdup - duplicates a string
 * @string: the string to duplicate
 *
 * Return: a pointer to the newly allocated duplicated string
 */
char *_strdup(char *string)
{
	char *duplicate;
	int i = 0, len;

	if (string == NULL)
		return (NULL);

	len = _strlen(string);

	duplicate = (char *)malloc(sizeof(char) * (len + 1));


	if (duplicate == NULL)
		return (NULL);

	while (string[i])
	{
		duplicate[i] = string[i];
		i++;
	}

	return (duplicate);
}
