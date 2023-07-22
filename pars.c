#include "minishell.h"

int main(int ac, char **av, char **env)
{
    int i = 0;

    pid_t pid = fork();
    int status;
    // char *str = "lsr";
    if(pid == 0)
    {
        i = execve(str, av, env);

        if(i == -1)
        {
            perror("execve");
            exit(1);
        }
    }
    else
        wait(NULL);

        return 0;
}