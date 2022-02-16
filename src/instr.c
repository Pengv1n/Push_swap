#include "push_swap.h"

void	push_stack(t_stk **a, t_stk **b, t_stk *new)
{
	new = NULL;

	if (*a)
	{
		new = (t_stk *)malloc(sizeof(t_stk));
		new->value = (*a)->value;
		add_front(b, new);
		*a = (*a)->next;
	}
}

void	r_stack(t_stk **top)
{
	t_stk	*tmp;

	tmp = NULL;
	if (*top && (*top)->next)
	{
		*top = (*top)->next;
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (*top)->prev;
		(*top)->prev->prev = tmp;
		tmp->next->next = NULL;
	}
}

void	rr_stack(t_stk **top)
{
	t_stk	*tmp;

	tmp = *top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *top;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*top)->prev = tmp;
	*top = tmp;
}

void	swap_stack(t_stk **top)
{
	int	i;

	i = (*top)->value;
	(*top)->value = (*top)->next->value;
	(*top)->next->value = i;
}