#include "minishell.h"

void rm(char **dp_command)
{
    int i;

    i = unlink(dp_command[1]);

    if(i == -1)
    {
        perror("zsh>$");
        return ;
    }
    return ;
}