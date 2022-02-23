#include "push_swap.h"

int	node_stk(t_stk **top, int idx)
{
	int i;
	t_stk	*tmp;

	i = 0;
	tmp = *top;
	while (tmp)
	{
		if (i == idx)
			return (tmp->value);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	check_low_val(t_stk *top, int val)
{
	while (top)
	{
		if (top->value <= val)
			return (1);
		top = top->next;
	}
	return (0);
}

void	lift_node_a(t_stk **a, t_stk **b, t_ps *ps, int m)
{
	if (size_stk(*a) / 2 > index_stk(*a, m))
		case_123(a, b, 2, ps);
	else
		case_123(a, b, 3, ps);
}

int	max_stk(t_stk *top)
{
	t_stk *tmp;
	int	max;

	if (top)
	{
		tmp = top;
		max = top->value;
		while (tmp)
		{
			if (max < tmp->value)
				max = tmp->value;
			tmp = tmp->next;
		}
		return (max);
	}
	return (0);
}

int	check_eq_val(t_stk *top, int val)
{
	while (top)
	{
		if (top->value == val)
			return (1);
		top = top->next;
	}
	return (0);
}

