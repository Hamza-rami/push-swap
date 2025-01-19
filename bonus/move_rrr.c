#include "push_swap_bonus.h"

void	rra(t_stack *a)
{
	t_node	*prev;
	t_node	*curren;

	if (a->top && a->top->next)
	{
		curren = a->top;
		while (curren->next)
		{
			prev = curren;
			curren = curren->next;
		}
		prev->next = NULL;
		curren->next = a->top;
		a->top = curren;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*prev;
	t_node	*curren;

	if (b->top && b->top->next)
	{
		curren = b->top;
		while (curren->next)
		{
			prev = curren;
			curren = curren->next;
		}
		prev->next = NULL;
		curren->next = b->top;
		b->top = curren;
	}
	write(1, "rrb\n", 4);
}

void	help_rra(t_stack *a)
{
	t_node	*prev;
	t_node	*curren;

	if (a->top && a->top->next)
	{
		curren = a->top;
		while (curren->next)
		{
			prev = curren;
			curren = curren->next;
		}
		prev->next = NULL;
		curren->next = a->top;
		a->top = curren;
	}
}

void	help_rrb(t_stack *b)
{
	t_node	*prev;
	t_node	*curren;

	if (b->top && b->top->next)
	{
		curren = b->top;
		while (curren->next)
		{
			prev = curren;
			curren = curren->next;
		}
		prev->next = NULL;
		curren->next = b->top;
		b->top = curren;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	help_rra(a);
	help_rrb(b);
	write(1, "rrr\n", 4);
}