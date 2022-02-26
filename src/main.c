#include "push_swap.h"

void	fill_stk(t_ps *ps, char **s, t_stk *new, int argc)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		new = (t_stk *)malloc(sizeof(t_stk));
		if (!new)
			ft_error("Error: malloc new");
		new->value = ft_atoi(s[i]);
		if (new->value > 2147483647 || new->value < -2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		new->next = NULL;
		new->prev = NULL;
		add_back(&ps->a, new);
		new = NULL;
	}
	if (argc == 2 || ps->fd != 1)
		free_split(ps->split);
}

t_ps	*init_stk(t_ps *ps)
{
	ps = (t_ps *) malloc(sizeof(t_ps));
	if (!ps)
		ft_error("Error: malloc ps");
	ps->a = NULL;
	ps->b = NULL;
	ps->split = NULL;
	ps->len = 0;
	ps->fd = 1;
	return (ps);
}

void	choice_input(t_ps *ps, int argc, char **argv)
{
	char	*line;

	if (!ft_strncmp(argv[1], "-f", ft_strlen(argv[1])))
	{
		ps->fd = open(argv[2], O_RDONLY);
		line = get_next_line(ps->fd);
		ps->split = ft_split(line, ' ');
		free(line);
		close(ps->fd);
	}
	else
	{
		if (argc == 2)
			ps->split = ft_split(argv[1], ' ');
		else
			ps->split = &argv[1];
	}
}

void	push_swap(t_ps *ps, int argc, char **argv)
{
	t_stk	*new;

	new = NULL;
	choice_input(ps, argc, argv);
	check_numb(ps->split);
	check_sim(ps->split);
	fill_stk(ps, ps->split, new, argc);
	if (check_sort_stk(ps->a))
		exit(EXIT_SUCCESS);
	ps->len = size_stk(ps->a);
	if (ps->len <= 10)
		sort_10(&(ps->a), &(ps->b), ps);
	else
		sort_big(&(ps->a), &(ps->b), ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	else
	{
		ps = init_stk(ps);
		push_swap(ps, argc, argv);
	}
	free(ps);
	ps = NULL;
	return (0);
}
