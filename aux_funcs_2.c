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

/**
 * _memset - fills the first n bytes of the memory area s with the byte c
 * @s: memory area to be filled
 * @c: the character with which to fill the memory area
 * @n: number of bytes to be filled
 *
 * Return: the c-filled memory area
 */
void *_memset(void *s, int c, int n)
{
	int index = 0;
	char *memory = s, val = c;

	while (index < n)
	{
		memory[index] = val;
		index++;
	}

	return (memory);
}
