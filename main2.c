#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char **tokenizer(char *input, int readchars)
{
    char *token, *token_aux, *input_aux, *delim = " \n";
    char **token_arr;
    int tokens = 0, index = 0;

    input_aux = malloc(sizeof(char) * (readchars + 1));
    memset(input_aux, 0, sizeof(char) * (readchars + 1));
    strcpy(input_aux, input);

    token = strtok(input, delim);
    while (token)
    {
        tokens++;
        token = strtok(NULL, delim);
    }
    tokens++;

    token_arr = malloc(sizeof(char *) * tokens);

    token = strtok(input_aux, delim);
    while (token)
    {
        token_arr[index] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(token_arr[index], token);
        token = strtok(NULL, delim);
        index++;
    }
    token_arr[index] = NULL;

    free(input_aux);

    return token_arr;
}


int main()
{
    char *input1 = "The quick brown fox";
    char **tokens1 = tokenizer(input1, strlen(input1));
    printf("Input: '%s'\n", input1);
    printf("Expected output: 'The', 'quick', 'brown', 'fox'\n");
    printf("Actual output: ");
    for (int i = 0; tokens1[i] != NULL; i++) {
        printf("'%s' ", tokens1[i]);
        free(tokens1[i]);
    }
    free(tokens1);
    printf("\n\n");

    char *input2 = "Hello\nworld!";
    char **tokens2 = tokenizer(input2, strlen(input2));
    printf("Input: '%s'\n", input2);
    printf("Expected output: 'Hello', 'world!'\n");
    printf("Actual output: ");
    for (int i = 0; tokens2[i] != NULL; i++) {
        printf("'%s' ", tokens2[i]);
        free(tokens2[i]);
    }
    free(tokens2);
    printf("\n\n");

    return 0;
}

