#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *get_loc(char *);
int cmd_exec(char *gtlc, char *args[], char *envp[]);
char **tokenizer(char *, int);

/* functions from aux_funcs_1.c */
int _strlen(char *);
char *_strcat(char *, char *);
int _strncmp(char *, char *, int);
char *_getenv(char *);
char *_strcpy(char *, char *);

/* functions from aux_funcs_2.c */
char *_strdup(char *str);
void *_memset(void *, int, int);

/* variables */
extern char **environ;

#endif
