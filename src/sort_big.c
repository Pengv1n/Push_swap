#include "push_swap.h"

int	choice(int len)
{
	if (len <= 200)
		return (ft_round(len / 4));
	else
		return (ft_round(len / 8));
}

void	mid1(t_stk **a, t_stk **b, int len)
{
	int		len_;
	int		m;
	t_stk	*sort_list;
	t_stk	*tmp;

	len_ = choice(len);
	while (len >= len_)
	{
		sort_list = copy_stk(*a);
		m = select_num(sort_list);
		while (check_low_val(*a, m) && (*a))
		{
			if ((*a)->value <= m)
			{
				tmp = *a;
				case_123(a, b, 1);
				free(tmp);
				len--;
			}
			else
				lift_node_a(a, b, m);
		}
		free_stk(&sort_list);
	}
}

void	mid2(t_stk **a, t_stk **b)
{
	int		min;
	t_stk	*tmp;

	while (*a && !check_sort_stk(*a))
	{
		min = min_stk(*a);
		tmp = (*a)->next;
		if ((*a)->value != min && tmp && tmp->value == min)
			case_123(a, b, 8);
		while (size_stk(*a) && check_low_val(*a, min))
		{
			if ((*a)->value == min)
			{
				tmp = *a;
				case_123(a, b, 1);
				free(tmp);
			}
			else
				lift_node_a(a, b, min);
		}
	}
}

void	mid3(t_stk **a, t_stk **b)
{
	t_stk	*tmp;
	int		max;

	tmp = NULL;
	max = max_stk(*b);
	while (check_eq_val((*b), max) && *b)
	{
		max = max_stk(*b);
		tmp = (*b)->next;
		if ((*b)->value != max && tmp && tmp->value == max)
			case_123(a, b, 7);
		while ((*b)->value != max && *b)
			lift_node_b(a, b, max);
		while (*b && (*b)->value == max)
		{
			tmp = *b;
			case_123(a, b, 4);
			max = max_stk(*b);
			free(tmp);
		}
	}
}

void	sort_big(t_stk **a, t_stk **b, t_ps *ps)
{
	if (ps->len <= 200)
		mid1(a, b, ps->len);
	else
		mid1(a, b, ps->len);
	mid2(a, b);
	mid3(a, b);
	free_stk(a);
	free_stk(b);
}
