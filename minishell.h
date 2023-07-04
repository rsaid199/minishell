#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

typedef struct all_vars
{
    char *command;
    char **dp_command;
}       t_vars;

int	ft_strcmp(const char *str1, const char *str2);
void ls();
void exec_value(char **dp_command, char **envp, t_vars *vars);
char	**ft_split(char *s, char c);
void dp_free(char **dp_command);
void cd(char **dp_command);
int ft_strlen(char *str);
void echo(char **dp_command);
void env(char **envp, char **dp_command);
void rm(char **dp_command);
void exit_f(char **dp_command, t_vars *vars);
void free_all(t_vars *vars);
void pwd();