#include "minishell.h"

int pipe_handler(char **dp_command)
{
    char **cmd1;
    char **cmd2;
    
}


int pipe_commands(const char* command1[], const char* command2[]) {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        close(pipefd[0]);

        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]); 

        execve(command1[0], (char* const*)command1, NULL);
        perror("execve (command1)");
        exit(1);
    } else {
        close(pipefd[1]);

        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]); 

        execve(command2[0], (char* const*)command2, NULL);
        perror("execve (command2)");
        exit(1);
    }

    return 0;
}
