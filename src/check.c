#include "push_swap.h"

void	check_sim(char **split)
{
	int i;
	int j;
	char	*s;

	i = -1;
	while (split[++i])
	{
		s = ft_strdup(split[i]);
		j = i;
		while (split[++j])
		{
			if (!ft_strncmp(split[i], split[j], ft_strlen(split[i])))
			{
				free(s);
				s = NULL;
				ft_error("Error: similar values");
			}
		}
		free(s);
		s = NULL;
	}
}

void	check_numb(char	**split)
{
	int i;
	int j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (!ft_isdigit(split[i][j]) && (((split[i][j] == '-')
			|| split[i][j] == '+') && !ft_isdigit(split[i][j + 1])))
				ft_error("Error: values incorrect");
		}
	}
}