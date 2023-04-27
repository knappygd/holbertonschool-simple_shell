#include "shell.h"

/*
 * This file contains function definitions for any required usage.
 * This file is limited to having up to only 5 function definitions
 * in order for it to be Betty-compliant.
 * More functions implemented in other files may not be present here;
 * refer to aux_funcs_1.c instead.
 *
 * Functions:
 *  - _strdup: Copies a string and stores it in a newly allocated address.
 *  - _memset: Fills the first n bytes of a memory area with determined bytes.
 *  - _strcspn: Returns the length of a string up to character c.
 *  - _strcmp: Compares two strings.
 *  - atoi4exit: Converts a positive integer. Not similar to atoi.
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

	for (i = 0; string[i]; i++)
		duplicate[i] = string[i];

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

	for (i = 0; i < n; i++)
		memory[i] = val;

	return (memory);
}

/**
 * rev_string - Reverses a string.
 * @s: The string to be reversed.
 */
void rev_string(char *s)
{
	int i = 0, len = 0;
	char aux;

	while (s[i++])
		len++;

	for (i = len - 1; i >= len / 2; i--)
	{
		aux = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = aux;
	}
}

/* === UNUSED === */

/**
 * _strcmp - Compares two strings.
 * @str1: A string to compare to str2.
 * @str2: A string to compare to str1.
 *
 * Return: The difference between both strings in ASCII values.
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] && str2[i]; i++)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);

	return (0);
}

/**
 * atoi4exit - Converts a positive integer. Not similar to atoi.
 * @str: The number to convert as a string.
 *
 * Return: 0 if no argument is passed or -1 if it's not positive or integer,
 * else the converted number.
 */
int atoi4exit(char *str)
{
	int result = 0;

	if (!str)
		result = 0;

	while (*str)
	{
		if (*str < '0' || *str > '9' || str[0] == '-')
		{
			result = -1;
			break;
		}

		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result);
}
