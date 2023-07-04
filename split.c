#include "minishell.h"

int	wordcounter(char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			x++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (x);
}

char	*maker(char *x, int start, int end)
{
	char	*z;
	int		i;

	i = 0;
	z = malloc(sizeof(char) * (end - start) + 1);
	if (!z)
		return (NULL);
	while (start < end)
	{
		z[i] = x[start];
		start++;
		i++;
	}
	z[i] = 0;
	return (z);
}

char	**ft_split(char *s, char c)
{
	char	**splitret;
	int		dpcounter;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	splitret = malloc((wordcounter(s, c) + 1) * sizeof(char *));
	if (!splitret)
		return (0);
	dpcounter = 0;
	start = -1;
	end = -1;
	while (++end <= ft_strlen(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || end == ft_strlen(s)) && start >= 0)
		{
			splitret[dpcounter++] = maker(s, start, end);
			start = -1;
		}
	}
	splitret[dpcounter] = NULL;
	return (splitret);
}
