#include "shell.h"

/*
 * This file contains the function implementations
 * required to execute built-in commands.
 * These are commands built into the shell itself,
 * unlike commands such as `ls` or `echo`, which are
 * executables.
 *
 * The built-ins included in this shell are:
 * - cd: Changes to a newly specified working directory
 * - exit: Exits the shell interface
 */

/**
 * change_dir - Changes to a newly specified working directory,
 * using the chdir() function.
 * @dir: A pointer to the directory to change.
 */
int change_dir(char *dir)
{
    if (!dir)
        dir = _getenv("HOME");
    
    int ret = chdir(dir);

    if (ret == -1)
    {
        perror("chdir");
        ret = 1;
    }
    return (ret);
}

void exit_sh(int exit_c)
{
    int ret;

    if (!exit_c)
        exit_c = 0;

    exit(exit_c);
}

int print_env(void)
{
    int i;

    for (i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);

    return (0);
}