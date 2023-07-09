#include "minishell.h"

void redir_l(char **dp_command)
{
    pid_t pid = fork();
    int fd;
    char *buf;
    char **dp_buf;
    buf = malloc(1000);
    int i = 0;
    int flag = 0;
    if(pid == 0)
    {
        fd = open(dp_command[2], O_RDONLY);
        read(fd, buf, 10000000);
        dp_buf = ft_split(buf, ' ');
        execve(dp_command[0], dp_buf, NULL);
    } 
    return ;
}

// int main()
// {
//     char *buf = malloc(1000);
//     read(0, buf, sizeof(buf));
//     write(1, buf, sizeof(buf));
//     free(buf);
//     return 0;
// }