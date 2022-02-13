#include "push_swap.h"

t_ps	*init_stk(t_ps *ps)
{
	ps = (t_ps *) malloc(sizeof(t_ps));
	if (!ps)
		ft_error("Error: malloc ps");
	ps->a = NULL;
	ps->b = NULL;
	ps->split = NULL;
	return (ps);
}

void	push_swap(t_ps *ps, int argc, char **argv)
{
	if (argc == 2)
		ps->split = ft_split(argv[1], ' ');
	else
		ps->split = &argv[1];
	check_numb(ps->split);
	check_numb(ps->split);
	
}

int main(int argc, char **argv)
{
	t_ps	*ps;

	ps = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	else
	{
		ps = init_stk(ps);

	}
	return (0);
}