#include "minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1[i])
	{
		if ((s1[i] != s2[i]) || s1[i] == 0 || s2[i] == 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
        i++;
    return(i);
}

void free_all(t_vars *vars)
{
	dp_free(vars->dp_command);
	free(vars->command);
	return ;
}

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

char	*ft_strjoin_with_free(char *s1, char *s2)
{
	int		i;
	int		s2i;
	char	*z;

	i = 0;
	s2i = 0;
	z = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!z)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			z[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[s2i] != '\0')
			z[i++] = s2[s2i++];
	}
	z[i] = '\0';
	// if(s1)
	// 	free(s1);
	// if(s2)
	// 	free(s2);
	return (z);
}