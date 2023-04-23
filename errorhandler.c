#include "shell.h"

char *err_constr(int flag, char *cmd, char *shellname)
{
    char *error = malloc(1024);
    int exit_code = 1;

    if (flag == -1)
        sprintf(error, "%s: %d: %s: not found", shellname, exit_code, cmd);

    return (error);
}