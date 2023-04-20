#include "shell.h"

/**
 * tokenizer - generates tokens from an input
 * @input: the string from which to tokenize
 *
 * Return: an array of tokens
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
