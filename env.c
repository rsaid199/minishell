#include "minishell.h"

void env(char **envp, char **dp_command)
{
    int i;
    char *value;

    i = 0;
    if(dp_command[1] == NULL)
    {
        while(envp[i] != NULL)
        {
            printf("%s\n", envp[i]);
            i++;
        }
    }
    else
    {
        value = getenv(dp_command[1]);
        if(value == NULL)
            perror(">$");
        printf("%s\n", value);
    }
        
    return ;
}