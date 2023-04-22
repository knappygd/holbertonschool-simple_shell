#include "shell.h"

/**
 * This file contains function definitions for any required usage.
 * This file is limited to having up to 5 function definitions
 * in order for it to be Betty-compliant.
 * More functions implemented in other files may not be present here;
 * refer to aux_funcs_2.c instead.
 *
 * Functions:
 *  - _strdup: Copies a string and stores it in a newly allocated address.
 *  - _memset: Fills the first n bytes of a memory area with determined bytes.
 */

/**
 * _strdup - Copies a string and stores it in a newly allocated address.
 * @string: The string to be duplicated.
 *
 * Return: A pointer to the newly allocated copy of the string.
 */
char *_strdup(char *string)
{
	char *duplicate;
	int i = 0, len;

	if (!string)
		return (NULL);

	len = _strlen(string);

	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicate)
		return (NULL);

	while (string[i])
	{
		duplicate[i] = string[i];
		i++;
	}

	return (duplicate);
}

/**
 * _memset - Fills the first n bytes of the memory area s with the byte c
 * @s: memory area to be filled
 * @c: the character with which to fill the memory area
 * @n: number of bytes to be filled
 *
 * Return: the c-filled memory area
 */
void *_memset(void *s, int c, int n)
{
	int i = 0;
	char *memory = s, val = c;

	while (i < n)
	{
		memory[i] = val;
		i++;
	}

	return (memory);
}
