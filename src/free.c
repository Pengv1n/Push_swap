#include "push_swap.h"

void	free_stk(t_stk **stk)
{
	t_stk *tmp;

	while (*stk)
	{
		tmp = (*stk)->next;
		free(*stk);
		*stk = NULL;
		(*stk) = tmp;
	}
}