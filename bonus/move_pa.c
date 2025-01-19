#include "push_swap_bonus.h"

void	pa(t_stack *a, t_stack *b)
{
	if (is_empty(b))
		return ;
	push(a, pop(b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	if (is_empty(a))
		return ;
	push(b, pop(a));
	write(1, "pb\n", 3);
}
