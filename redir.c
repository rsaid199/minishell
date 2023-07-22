#include "minishell.h"

void redir_l(char **dp_command)
{
    
    int fd;
    char *buf;
    char **dp_buf;
    buf = malloc(1000);
    int i = 0;
    int flag = 0;
    pid_t pid = fork();
    if(pid == 0)
    {
        fd = open(dp_command[2], O_RDONLY);
        read(fd, buf, 10000000);
        dp_buf = ft_split(buf, ' ');
        execve(dp_command[0], dp_buf, NULL);
        return ;
    }
    else
        {
            int child_status;
            pid_t child_pid = wait(&child_status);
        }
    return ;
}

void redir_r(char **dp_command)
{
    
    int pipefd[2];
    pipe(pipefd);

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return ;
    }

    if (child_pid == 0) {
        close(pipefd[0]);

        int filefd = open(dp_command[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (filefd == -1) {
            perror("open");
            return ;
        }

        dup2(filefd, STDOUT_FILENO);
        char *argv[] = {dp_command[0], NULL};

        execve(dp_command[0], argv, NULL);
        perror("execve");
        exit(1);
    } else {
        close(pipefd[1]);
        wait(NULL);

        return ;
    }
}

void redir_rr(char **dp_command)
 {
    int fd = open(dp_command[2], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("Failed to open the file");
        return;
    }

    int stdout_fd = dup(STDOUT_FILENO);

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("Failed to redirect output to the file");
        close(fd);
        return;
    }

    int is_executable = access(dp_command[0], X_OK);
    if (is_executable == 0) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Failed to fork");
            close(fd);
            return;
        } else if (pid == 0) {
            char* const args[] = { dp_command[0], NULL };
            execve(dp_command[0], args, NULL);

            perror("Failed to execute the program");
            exit(1);
        }
    } 
    dup2(stdout_fd, STDOUT_FILENO);

    close(fd);
}