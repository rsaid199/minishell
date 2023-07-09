#include "minishell.h"
int red_check(char **dp_command)
{
    int i;
    int x;

    i = 0;
    x = 0;

    while(dp_command[i])
    {
        while(dp_command[i][x])
        {
            if(dp_command[i][x] == '<')
                return(5);
            x++;
        }
        i++;
        x = 0;
    }
    return 0;
}
void exec_value(char **dp_command, char **envp, t_vars *vars)
{
    int left_redir = red_check(dp_command);

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
    else if(left_redir == 5)
        redir_l(dp_command);
    else
        write(2, "invalid command\n", 16);
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