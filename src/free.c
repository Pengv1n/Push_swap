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

void    free_split(char **split)
{
    int i;

    i = -1;
    while (split[++i])
        free(split[i]);
    free(split);
}