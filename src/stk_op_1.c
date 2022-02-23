#include "push_swap.h"

void	add_back(t_stk **top, t_stk *new)
{
	t_stk	*tmp;

	if (!*top)
		*top = new;
	else
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int	size_stk(t_stk *stk)
{
	int	i;
	t_stk	*tmp;

	tmp = stk;
	i = 0;
	while(tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

int	check_sort_stk(t_stk *stk)
{
	t_stk *tmp;

	tmp = stk;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	add_front(t_stk **top, t_stk *new)
{
	new->next = *top;
	new->prev = NULL;
	if (*top)
		(*top)->prev = new;
	*top = new;
}

t_stk	*bottom(t_stk *top)
{
	t_stk *ret;

	ret = top;
	while (ret->next)
		ret = ret->next;
	return (ret);
}