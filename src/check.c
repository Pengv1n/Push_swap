#include "push_swap.h"

void	check_sim(char **split)
{
	int		i;
	int		j;
	int		k1;
	int		k2;

	i = -1;
	while (split[++i])
	{
		j = i;
		while (split[++j])
		{
			k1 = ft_atoi(split[i]);
			k2 = ft_atoi(split[j]);
			if (k1 == k2)
				ft_error("Error: similar values");
		}
	}
}

void	check_numb(char	**split)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j])
		{
			if (((split[i][j] == '-')
				|| split[i][j] == '+') && ft_isdigit(split[i][j + 1]))
				continue ;
			else if (!ft_isdigit(split[i][j]))
				ft_error("Error: values incorrect");
		}
	}
}
