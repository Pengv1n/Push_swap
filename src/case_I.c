#include "push_swap.h"

void	case_78(t_stk **a, t_stk **b, int code, t_ps *ps)
{
	if (code == 7 && (*b) && (*b)->next)
	{
		ft_putstr_fd("sb\n", 1);
		swap_stack(b);
	}
	if (code == 8 && (*a) && (*a)->next)
	{
		ft_putstr_fd("sa\n", 1);
		swap_stack(a);
	}
}

void	case_456(t_stk **a, t_stk **b, int code, t_ps *ps)
{
	t_stk	*tmp;

	tmp = NULL;
	if (code == 4)
	{
		ft_putstr_fd("pa\n", 1);
		push_stack(b, a, tmp);
		free(tmp);
	}
	if (code == 5)
	{
		ft_putstr_fd("rb\n", 1);
		r_stack(b);
	}
	if (code == 6 && (*b)->next)
	{
		ft_putstr_fd("rrb\n", 1);
		rr_stack(b);
	}
	else
		case_78(a, b , code, ps);
}

void	case_123(t_stk **a, t_stk **b, int code, t_ps *ps)
{
	t_stk *tmp;

	tmp = NULL;
	if (code == 1)
	{
		ft_putstr_fd("pb\n", 1);
		push_stack(a, b, tmp);
		free(tmp);
	}
	if (code == 2)
	{
		ft_putstr_fd("ra\n", 1);
		r_stack(a);
	}
	if (code == 3 && (*a)->next)
	{
		ft_putstr_fd("rra\n", 1);
		rr_stack(a);
	}
	else
		case_456(a, b, code, ps);
}