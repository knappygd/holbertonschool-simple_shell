#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*
 * This is the shell header file.
 * Here are declared the prototypes of all functions implemented
 * across all files, as well as variables.
 * All includes are within this header file as well.
 * Function declaration should be in ANSI style,
 * including both the type and parameter names.
 */

/*
 * Declarations of the shell core functions.
 *
 * The definitions can be found at:
 *  - get_loc: getlocation.c
 *  - cmd_exec: cmdexec.c
 *  - tokenizer: tokenizer.c
 *  - err_constr: errorhandler.c
 */
char *get_loc(char *command);
int cmd_exec(char *input);
char **tokenizer(char *input, int readchars);
char *err_constr(int flag, char *cmd, char *shellname);

/*
 * Input handling.
 *
 * The definitions can be found at inputhandler.c
 */
int input_flags(char *input);
int handle(char *input, char *shellname);

/*
 * Built-in commands functions.
 *
 * The definitions of these functions can be found at builtin.c
 */
void change_dir(char *dir);

/* Functions from aux_funcs_1.c */
int _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_getenv(char *envr);
int _strncmp(char *str1, char *str2, int n);
char *_strcpy(char *dest, char *src);

/* Functions from aux_funcs_2.c */
char *_strdup(char *string);
void *_memset(void *s, int c, int n);
int _strcspn(char *string, char c);
int _strcmp(char *str1, char *str2);

/* Variables */
extern char **environ;

#endif
