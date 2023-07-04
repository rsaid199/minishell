#include "minishell.h"

void pwd()
{
    char buf[PATH_MAX];

    if (getcwd(buf, sizeof(buf)) == NULL) {
        perror("getcwd() error");
        return ;
    }

    printf("%s\n", buf);
}