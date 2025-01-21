/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:14 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 13:00:40 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_bonus(t_stack_bonus *a)
{
	t_node_stack	*prev;
	t_node_stack	*curren;

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

void	rrb_bonus(t_stack_bonus *b)
{
	t_node_stack	*prev;
	t_node_stack	*curren;

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

void	help_rra_bonus(t_stack_bonus *a)
{
	t_node_stack	*prev;
	t_node_stack	*curren;

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

void	help_rrb_bonus(t_stack_bonus *b)
{
	t_node_stack	*prev;
	t_node_stack	*curren;

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

void	rrr_bonus(t_stack_bonus *a, t_stack_bonus *b)
{
	help_rra_bonus(a);
	help_rrb_bonus(b);
}
