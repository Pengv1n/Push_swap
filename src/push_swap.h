#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_stack
{
	int	value;
	struct s_stack	*prev;
	struct s_stack	*next;
} t_stk;

typedef struct s_ps
{
	t_stk *a;
	t_stk *b;
	char **split;
	char **argv;
	int	argc;
} t_ps;

void	ft_error(char *str);
void	check_sim(char **split);
void	check_numb(char	**split);

#endif
