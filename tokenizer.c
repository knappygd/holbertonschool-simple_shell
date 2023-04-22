#include "shell.h"

/**
 * This file contains the tokenizer() function, responsible for
 * splitting the input into tokens and storing them into an array.
 * It is useful for identifying the command and its arguments, if any,
 * in subsequent processes.
 * It makes use of the strtok() function.
 */

/**
 * tokenizer - Generates tokens from an input and stores them
 * into an array of pointers to the tokens.
 * @input: The string to split.
 * @readchars: The number of characters that the input has.
 *
 * Return: An array of pointers to the tokens.
 */
char **tokenizer(char *input, int readchars)
{
	char *token, *token_aux, *input_aux, *delim = " \n";
	char **token_arr;
	int tokens = 0, index = 0;

	input_aux = malloc(sizeof(char) * readchars);
	_memset(input_aux, 0, sizeof(char) * (readchars + 1));
	_strcpy(input_aux, input);

	token = strtok(input, delim);
	while (token)
	{
		tokens++;
		token = strtok(NULL, delim);
	}

	token_arr = malloc(sizeof(char *) * tokens);

	token = strtok(input_aux, delim);

	while (token)
	{
		token_arr[index] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(token_arr[index], token);
		token = strtok(NULL, delim);
		index++;
	}
	token_arr[index] = NULL;

	free(input_aux);

	return (token_arr);
}
