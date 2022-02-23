#include "push_swap.h"

#include "stdio.h"

void	mid1(t_stk **a, t_stk **b, int len, t_ps *ps)
{
	int	len_;
	int m;
	t_stk	*sort_list;
	t_stk	*tmp;

	len_ = ft_round(len / 4);
	while (len >= len_)
	{
		sort_list = copy_stk(*a);
		m = select_num(sort_list);
		while (check_low_val(*a, m) && (*a))
		{
			if ((*a)->value <= m)
			{
				tmp = *a;
				case_123(a, b, 1, ps);
				free(tmp);
				len--;
			}
			else
				lift_node_a(a, b, ps ,m);
		}
		free_stk(&sort_list);
	}
}

void	mid2(t_stk **a, t_stk **b, t_ps *ps)
{
	int	min;
	t_stk	*tmp;

	while (*a && !check_sort_stk(*a))
	{
		min = min_stk(*a);
		tmp = (*a)->next;
		if	((*a)->value != min && tmp && tmp->value == min)
			case_123(a, b, 8, ps);
		while (size_stk(*a) && check_low_val(*a, min))
		{
			if ((*a)->value == min)
			{
				tmp = *a;
				case_123(a, b, 1, ps);
				free(tmp);
			}
			else
				lift_node_a(a, b, ps, min);
		}
	}
}

void	mid3(t_stk **a, t_stk **b, t_ps *ps)
{
	t_stk	*tmp;
	int	max;

	tmp = NULL;
	max = max_stk(*b);
	while (check_eq_val((*b), max) && *b)
	{
		max = max_stk(*b);
		tmp = (*b)->next;
		if ((*b)->value != max && tmp && tmp->value == max)
			case_123(a, b, 7, ps);
		while ((*b)->value != max && *b)
			lift_node_b(a, b, ps, max);
		while (*b && (*b)->value == max)
		{
			tmp = *b;
			case_123(a, b, 4, ps);
			max = max_stk(*b);
			free(tmp);
		}
	}
}

void	sort_mid(t_stk **a, t_stk **b, t_ps *ps)
{
	mid1(a, b, ps->len, ps);
	mid2(a, b, ps);
	mid3(a, b, ps);
	free_stk(a);
	free_stk(b);
}