/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:11 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 13:00:19 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_bonus(t_stack_bonus *a)
{
	t_node_stack	*tmp;
	t_node_stack	*curren;

	if (a->top && a->top->next)
	{
		tmp = a->top;
		a->top = a->top->next;
		curren = a->top;
		while (curren->next)
		{
			curren = curren->next;
		}
		curren->next = tmp;
		tmp->next = NULL;
	}
}

void	rb_bonus(t_stack_bonus *b)
{
	t_node_stack	*tmp;
	t_node_stack	*curren;

	if (b->top && b->top->next)
	{
		tmp = b->top;
		b->top = b->top->next;
		curren = b->top;
		while (curren->next)
		{
			curren = curren->next;
		}
		curren->next = tmp;
		tmp->next = NULL;
	}
}

void	help_ra_bonus(t_stack_bonus *a)
{
	t_node_stack	*tmp;
	t_node_stack	*curren;

	if (a->top && a->top->next)
	{
		tmp = a->top;
		a->top = a->top->next;
		curren = a->top;
		while (curren->next)
		{
			curren = curren->next;
		}
		curren->next = tmp;
		tmp->next = NULL;
	}
}

void	help_rb_bonus(t_stack_bonus *b)
{
	t_node_stack	*tmp;
	t_node_stack	*curren;

	if (b->top && b->top->next)
	{
		tmp = b->top;
		b->top = b->top->next;
		curren = b->top;
		while (curren->next)
		{
			curren = curren->next;
		}
		curren->next = tmp;
		tmp->next = NULL;
	}
}

void	rr_bonus(t_stack_bonus *a, t_stack_bonus *b)
{
	help_ra_bonus(a);
	help_rb_bonus(b);
	write(1, "rr\n", 3);
}
