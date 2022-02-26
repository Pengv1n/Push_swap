#include "push_swap.h"

int	ft_round(float m)
{
	int	i;

	i = (int) m;
	if ((m - i) >= 0.5)
		return (i + 1);
	else
		return (i);
}
