#include "minishell.h"

void cd(char **dp_command)
{
    int i;

    i = chdir(dp_command[1]);
    if(i == -1)
        perror("zsh>$");
    return ;
}