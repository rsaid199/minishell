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
#include <sys/wait.h>

extern char** environ;

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
int parser(char **dp_command);
int check_ds(char **dp_command, int x);
void redir_l(char **dp_command);
char	*ft_strjoin_with_free(char *s1, char *s2);
void redir_r(char **dp_command);
void redir_rr(char **dp_command);
void handler(char **dp_command);
int set_env_variable(const char* variable, const char* value);