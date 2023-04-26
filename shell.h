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
int cmd_exec(char *path, char **args, char *envp[]);
char **tokenizer(char *input, int readchars);
int err_constr(int flag, int exit, char **args, char *shellname);
int builtin_handler(char **args, char *shellname, int i);
int is_builtin(char *cmd);

/*
 * Input handling.
 *
 * The definitions can be found at inputhandler.c
 */
int input_flags(char *input, char *shellname);
int handle(int flag, char *path, char **args, char *envp[], char *shn, int i);

/*
 * Built-in commands functions.
 *
 * The definitions of these functions can be found at builtin.c
 */
int change_dir(char *dir);
void exit_sh(int exit_c);
int print_env(void);

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
int atoi4exit(char *str);

/* Variables */
extern char **environ;

#endif
