#include "push_swap.h"

void	min_to_top(t_stk **a, t_stk **b, int min)
{
	int	idx;
	int	mid;

	idx = index_stk((*a), min);
	mid = (size_stk(*a)) / 2;
	if (mid > idx)
		case_123(a, b, 2);
	else
		case_123(a, b, 3);
}

void	sort_more3(t_stk **a, t_stk **b, t_ps *ps)
{
	int		len_;
	int		min;
	t_stk	*t;

	len_ = ps->len;
	while (len_ > 3)
	{
		min = min_stk(*a);
		t = (*a)->next;
		if ((*a)->value != min && t && t->value == min)
			case_123(a, b, 8);
		while ((*a)->value != min)
			min_to_top(a, b, min);
		t = *a;
		case_123(a, b, 1);
		free(t);
		len_--;
	}
}

void	sort_3_i83_i82(t_stk **a, t_stk **b, int code)
{
	case_123(a, b, 8);
	case_123(a, b, code);
}

void	sort_3(t_stk **a, t_stk **b)
{
	t_stk	*bott;
	int		min;

	bott = bottom(*a);
	min = min_stk(*a);
	while (!check_sort_stk(*a))
	{
		if ((*a)->value < (*a)->next->value && bott->value == min)
			case_123(a, b, 3);
		else if ((*a)->value > (*a)->next->value && bott->value == min)
			sort_3_i83_i82(a, b, 3);
		else if ((*a)->next->value == min)
		{
			if ((*a)->value < bott->value)
				case_123(a, b, 8);
			else
				case_123(a, b, 2);
		}
		else if ((*a)->value == min)
			sort_3_i83_i82(a, b, 2);
	}
}

void	sort_10(t_stk **a, t_stk **b, t_ps *ps)
{
	t_stk	*tmp;

	tmp = NULL;
	if (ps->len == 2 && (*a)->value > (*a)->next->value)
		case_123(a, b, 8);
	if (ps->len <= 3)
		sort_3(a, b);
	if (ps->len > 3)
	{
		sort_more3(a, b, ps);
		sort_3(a, b);
		while (*b)
		{
			tmp = *b;
			case_123(a, b, 4);
			free(tmp);
		}
		free_stk(b);
	}
	free_stk(a);
}
