#include "push_swap_bonus.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->top && a->top->next)
	{
		tmp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->top && b->top->next)
	{
		tmp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = tmp;
	}
	write(1, "sb\n", 3);
}

void	help_sa(t_stack *a)
{
	int	tmp;

	if (a->top && a->top->next)
	{
		tmp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = tmp;
	}
}

void	help_sb(t_stack *b)
{
	int	tmp;

	if (b->top && b->top->next)
	{
		tmp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = tmp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	help_sa(a);
	help_sb(b);
	write(1, "ss\n", 3);
}