#include "push_swap.h"

int	min_stk(t_stk *top)
{
	int	ret;
	t_stk	*tmp;

	tmp = top;
	ret = tmp->value;
	while (tmp)
	{
		if (tmp->value < ret)
			ret = tmp->value;
		tmp = tmp->next;
	}
	return (ret);
}

int	index_stk(t_stk *top, int n)
{
	int i;
	t_stk *tmp;

	i = 1;
	tmp = top;
	while (tmp)
	{
		if (tmp->value <= n)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}