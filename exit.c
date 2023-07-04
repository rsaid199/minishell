#include "minishell.h"

void exit_f(char **dp_command, t_vars *vars)
{
    // printf("%s\n", vars->command);
    free_all(vars);
    exit(0);
}  