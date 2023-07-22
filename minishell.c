#include "minishell.h"

int red_check(char **dp_command)
{
    int i;
    int x;

    i = 0;
    x = 0;

    while(dp_command[i])
    {
        while(dp_command[i][x] && dp_command[i])
        {
            if(dp_command[i][x] == '<')
                return(1);
            else if(dp_command[i][x] == '>')
                return(2);
            else if (ft_strcmp(dp_command[i], ">>") == 0)
                return (3);
            x++;
        }
        i++;
        x = 0;
    }
    return 0;
}
void exec_value(char **dp_command, char **envp, t_vars *vars)
{
    int redir = red_check(dp_command);
    if(redir == 0)
    {
        if(ft_strcmp(dp_command[0], "ls") == 0 || ft_strcmp(dp_command[0], "\"ls\"") == 0)
            ls();
        else if(ft_strcmp(dp_command[0], "cd") == 0)
            cd(dp_command);
        else if(strcmp(dp_command[0], "echo") == 0)
            echo(dp_command);
        else if(strcmp(dp_command[0], "env") == 0)
            env(envp, dp_command);
        else if (ft_strcmp(dp_command[0], "rm") == 0)
            rm(dp_command);
        else if(ft_strcmp(dp_command[0], "exit") == 0)
            exit_f(dp_command, vars);
        else if(ft_strcmp(dp_command[0], "pwd") == 0)
            pwd();
        else if(ft_strcmp(dp_command[0], "export") == 0)
            handler(dp_command);
        else
            write(2, "invalid command\n", 16);
    }
    else
    {
        if(redir == 1)
            redir_l(dp_command);
        else if(redir == 2)
            redir_r(dp_command);
        else if (redir == 3)
            redir_rr(dp_command); 
    }

    return ;
}

int main(int ac, char **av, char **envp)
{
    t_vars vars;
    int i = 2;

    while(1)
    {
        vars.command = readline("zsh>$");
        add_history(vars.command);
        vars.dp_command = ft_split(vars.command, ' ');
        i = parser(vars.dp_command);
        if(i == 0)
            exec_value(vars.dp_command, envp, &vars);
        else
            free_all(&vars);
    }
}