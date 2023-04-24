#include "shell.h"

int builtin_handler(char **args, char *shellname)
{
    int exit = 0;

    if (_strcmp(args[0], "cd") == 0)
    {
        exit = change_dir(args[1]);
    }
    else if (_strcmp(args[0], "exit") == 0)
    {
        if (!args[1])
            exit_sh(0);

        else
        {
            if (atoi4exit(args[1]) == -1)
            {
                exit = 1;
                err_constr(-7, exit, args, shellname);
            }

            else
                exit_sh(atoi4exit(args[1]));
        }
    }

    return (exit);
}