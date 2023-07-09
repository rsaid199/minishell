#include "minishell.h"

int check_ds(char **dp_command, int x)
{
    if(dp_command[x][0] == '"')
        return 1;
    else if(dp_command[x][0] == '\'')
        return 2;
    else 
        return 0;
}

int parser(char **dp_command)
{
    int i;
    int x;
    int checker;
    int count = 0;
    int flag = 0;
    x = 0;
    i = 0;
    
    while(dp_command[x])
    {
        checker = check_ds(dp_command, x);
        if(checker == 1)
        {
            while(dp_command[x][i])
            {
                if(dp_command[x][i] == '"')
                    count++;
                if(dp_command[x][i] == '\'')
                    flag++;
                i++;
            }
            if(count != 2 || (dp_command[x][ft_strlen(dp_command[x]) - 1] != '"') || flag > 0)
            {
                printf("invalid notation\n");
                return 1;
            }
        }
        else if(checker == 2)
        {
            while(dp_command[x][i])
            {
                if(dp_command[x][i] == '\'')
                    count++;
                if(dp_command[x][i] == '"')
                    flag++;
                i++;
            }
            if(count != 2 || (dp_command[x][ft_strlen(dp_command[x]) - 1] != '\'') || flag > 0)
            {
                printf("invalid notation\n");
                return 1;
            }
        }
        x++;
        i = 0;
        count = 0;
        flag = 0;
    }
    return 0;
}