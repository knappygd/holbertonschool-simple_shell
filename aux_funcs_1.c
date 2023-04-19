#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @string: the string to count
 *
 * Return: number of characters
 */
int _strlen(char *string)
{
	int length = 0;

	while (*string++)
		length++;

	return (length);
}

/**
 * _strcat - concatenates two strings and stores the result in the destination string * @dest: str1
 * @src: str2
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
        int i = 0, n = 0;

        while (dest[i] != '\0')
        {
                i++;
        }

        while (src[n] != '\0')
        {
                dest[i] = src[n];
                i++;
                n++;
        }

        dest[i] = '\0';

        return (dest);
}

/**
 * _getenv - gets the environment variable from the PATH. similat to getenv()
 * @envr: environment variable to get
 *
 * Return: a pointer to the environment variable
 */
char *_getenv(char *envr)
{
	int index = 0, len = _strlen(envr);

	while (environ[index])
	{
		if (_strncmp(envr, environ[index], len) == 0)
			return (environ[index] + len + 1);
		index++;
	}

	return (NULL);
}

/**
 * _strncmp - compares n bytes between two strings
 * @str1: string to compare
 * @str2: string to compare
 * @n: bytes to compare
 *
 * Return: the difference between strings
 */
int _strncmp(char *str1, char *str2, int n)
{
	int index = 0;

	while (index < n && str1[index] && str2[index])
	{
		if (str1[index] > str2[index])
			return (str1[index] - str2[index]);
		else if (str1[index] < str2[index])
			return (str1[index] - str2[index]);
		index++;
	}

	if (index == n)
		return (0);
}

/**
 * _strcpy - copies the source string to the destination string
 * @dest: destination string
 * @src: source string
 *
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
