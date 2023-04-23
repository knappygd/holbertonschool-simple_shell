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
void change_dir(char *dir)
{
    int ret = chdir(dir);

    if (ret == -1)
    {
        perror("chdir");
    }
}