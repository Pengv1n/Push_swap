#include "push_swap.h"

int	index_max(t_stk *a, int m)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->value >= m)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	lift_node_b(t_stk **a, t_stk **b, int max)
{
	if (ft_round(size_stk(*b) / 2) > index_max(*b, max) && *b)
		case_123(a, b, 5);
	else if (*b)
		case_123(a, b, 6);
}
