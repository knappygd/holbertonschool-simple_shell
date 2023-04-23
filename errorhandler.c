#include "shell.h"

char *err_constr(int flag, int exit, char *cmd, char *shellname)
{
    char *error = malloc(1024);

    if (flag == -1)
        sprintf(error, "%s: %d: %s: not found", shellname, exit, cmd);

    return (error);
}