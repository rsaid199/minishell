#include "minishell.h"

void ls()
{
    char path[PATH_MAX];
    DIR *dir;
    struct dirent *entry;
    int i = 0;

    getcwd(path, sizeof(path));
    dir = opendir(path);

    while((entry = readdir(dir)) != NULL)
    {
        if(ft_strcmp(entry->d_name, "..") != 0 && ft_strcmp(entry->d_name, ".") != 0)
            printf("%s ", entry->d_name);
    }
    printf("\n");
    closedir(dir);
}

int main()
{
    ls();
    return 0;
}