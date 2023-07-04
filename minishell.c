#include "minishell.h"

void dp_free(char **dp_command)
{
    int i;

    i = 0;

    while(dp_command[i])
    {
        free(dp_command[i]);
        i++;
    }
    free(dp_command);
    return;
}

void exec_value(char **dp_command, char **envp, t_vars *vars)
{

    if(ft_strcmp(dp_command[0], "ls") == 0)
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
    else
        write(2, "invalid command\n", 16);
    return ;
}

int main(int ac, char **av, char **envp)
{
    t_vars vars;
    int i = 0;

    while(1)
    {
        vars.command = readline("zsh>$");
        add_history(vars.command);
        vars.dp_command = ft_split(vars.command, ' ');
        exec_value(vars.dp_command, envp, &vars);
        free_all(&vars);
    }
}