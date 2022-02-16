#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include "stdio.h"

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
	int	len;
} t_ps;

void	ft_error(char *str);
void	check_sim(char **split);
void	check_numb(char	**split);
void	add_back(t_stk **top, t_stk *new);
void	free_stk(t_stk **stk);
int		size_stk(t_stk *stk);
int		check_sort_stk(t_stk *stk);
void	add_front(t_stk **top, t_stk * new);
void	push_stack(t_stk **a, t_stk **b, t_stk *new);
void	case_123(t_stk **a, t_stk **b, int code, t_ps *ps);
void	r_stack(t_stk **top);
void	sort_10(t_stk **a, t_stk **b, t_ps *ps);
void	rr_stack(t_stk **top);
void	swap_stack(t_stk **top);
t_stk	*bottom(t_stk *top);
int		min_stk(t_stk *top);
int		index_stk(t_stk *top, int n);
#endif
