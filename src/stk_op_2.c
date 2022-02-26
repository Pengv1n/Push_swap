#include "push_swap.h"

int	min_stk(t_stk *top)
{
	int		ret;
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
	int		i;
	t_stk	*tmp;

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

t_stk	*copy_stk(t_stk *top)
{
	t_stk	*tmp;
	t_stk	*ret;

	tmp = (t_stk *)malloc(sizeof(t_stk));
	ft_bzero(tmp, sizeof(t_stk));
	ret = tmp;
	while (top)
	{
		tmp->value = top->value;
		if (top->next)
		{
			tmp->next = (t_stk *)malloc(sizeof(t_stk));
			ft_bzero(tmp->next, sizeof(t_stk));
			tmp = tmp->next;
		}
		top = top->next;
	}
	return (ret);
}

t_stk	*sort_stk(t_stk *top)
{
	t_stk	*tmp;
	t_stk	*tmp2;
	t_stk	*min;
	int		i;

	tmp = top;
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (min->value > tmp2->value)
				min = tmp2;
			tmp2 = tmp2->next;
		}
		i = tmp->value;
		tmp->value = min->value;
		min->value = i;
		tmp = tmp->next;
	}
	return (top);
}

int	select_num(t_stk *a)
{
	t_stk	*tmp;
	int		len;
	int		m;

	m = 0;
	len = size_stk(a);
	tmp = sort_stk(a);
	if (len <= 12)
		m = ft_round(len / 2);
	else if (len < 200)
		m = ft_round(len / 4);
	else if (len >= 200)
		m = ft_round(len / 8);
	return (node_stk(&tmp, m));
}
