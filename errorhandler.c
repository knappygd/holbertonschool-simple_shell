#include "shell.h"

int err_constr(int flag, int exit, char **args, char *shellname)
{
    char *error = malloc(1024);
    char *cmd = args[0];

    if (flag == -1)
        sprintf(error, "%s: %d: %s: not found", shellname, exit, cmd);
    else if (flag == -7)
        sprintf(error, "%s: %d: %s: Illegal number: %s", shellname, exit, cmd, args[1]);
    else if (flag == -8)
    {
        sprintf(error, "%s: %d: %s: can't cd to %s", shellname, exit, cmd, args[1]);
    }

    printf("%s\n", error);
    free(error);

    return (0);
}