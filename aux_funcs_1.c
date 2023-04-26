#include "shell.h"

/*
 * This file contains function definitions for any required usage.
 * This file is limited to having up to only 5 function definitions
 * in order for it to be Betty-compliant.
 * More functions implemented in other files may not be present here;
 * refer to aux_funcs_2.c instead.
 *
 * Functions:
 *  - _strlen: Returns the length of a string.
 *  - _strcat: Concatenates two strings and returns the result.
 *  - _getenv: Retrieves the value of an environment variable.
 *  - _strncmp: Compares two strings up to n bytes.
 *  - _strcpy: Copies a string from one location to another.
 */

/**
 * _strlen - Returns the length of a string.
 * @string: The string from which to count the characters.
 *
 * Return: The length of the string.
 */
int _strlen(char *string)
{
	int length = 0;

	while (*string++)
		length++;

	return (length);
}

/**
 * _strcat - Concatenates two strings and returns the result.
 * @dest: The string to which append src.
 * @src: The string appended to dest.
 *
 * Return: dest; the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, n = 0;

	while (dest[i])
		i++;

	while (src[n])
	{
		dest[i] = src[n];
		i++;
		n++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 * @envr: Environment variable to retrieve.
 *
 * Return: A pointer to the environment variable.
 */
char *_getenv(char *envr)
{
	int i, len = _strlen(envr);

	for (i = 0; environ[i]; i++)
		if (_strncmp(envr, environ[i], len) == 0)
			return (environ[i] + len + 1);

	return (NULL);
}

/**
 * _strncmp - Compares two strings up to n bytes.
 * @str1: A string to compare to str2.
 * @str2: A string to compare to str1.
 * @n: The first n bytes to compare.
 * If n = strlen(str), considering both strings have the same length,
 * then it compares the whole string.
 *
 * Return: The difference between strings.
 */
int _strncmp(char *str1, char *str2, int n)
{
	int index;

	for (index = 0; index < n && str1[index] && str2[index]; index++)
	{
		if (str1[index] > str2[index])
			return (str1[index] - str2[index]);
		else if (str1[index] < str2[index])
			return (str1[index] - str2[index]);
	}

	if (index == n)
		return (0);
}

/**
 * _strcpy - Copies a string from one location to another.
 * @dest: Location to which copy src to.
 * @src: The string to be copied to dest.
 *
 * Return: The location of the copied string.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
