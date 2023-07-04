#include "minishell.h"

void echo(char **dp_command)
{  
    int i;

    i = 1;
    while(dp_command[i])
    {
        printf("%s ", dp_command[i]);
        i++;
    }
    printf("\n");
    return ;
}