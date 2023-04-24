#include "shell.h"

int builtin_handler(char **args, char *shellname, int index)
{
    int exit = 0;

    switch (index)
    {
    case 1:
        if (!args[1])
            exit = change_dir(_getenv("HOME"));
        else
            exit = change_dir(args[1]);
        if (exit == 1)
                err_constr(-8, exit, args, shellname);
        break;
    case 2:
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
        case 3:
        exit = print_env();
        break;
    default:
        break;
    }

    return (exit);
}

int is_builtin(char *cmd)
{
    char *builtin_arr[] = {"cd", "exit", "env", NULL};
    int i;

    for (i = 0; builtin_arr[i]; i++)
        if (_strcmp(cmd, builtin_arr[i]) == 0)
            return (i + 1);

    return (-1);
}