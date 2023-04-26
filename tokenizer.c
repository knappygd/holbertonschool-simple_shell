#include "shell.h"

/*
 * This file contains the tokenizer() function, responsible for
 * splitting the input into tokens and storing them into an array.
 * It is useful for identifying the command and its arguments, if any,
 * in subsequent processes.
 * It makes use of the strtok() function.
 * Tokenizer should be used with the input ONLY once, as it is a
 * highly destructive function and the input can't be recovered.
 * In case it needs to be used more than once, it's recommended
 * to tokenize a duplicate of the input.
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
	char *token, *token_aux, *input_aux, *delim = " \n", **token_arr;
	int tokens = 0, index = 0;

	if (!input)
		return (NULL);

	input_aux = malloc(sizeof(char) * readchars);
	if (!input_aux)
		return (NULL);
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
		if (!token_arr[index])
			return (NULL);
		_strcpy(token_arr[index], token);
		token = strtok(NULL, delim);
		index++;
	}
	token_arr[index] = NULL;

	free(input_aux);

	return (token_arr);
}
