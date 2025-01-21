/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:17 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 13:00:54 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_bonus(t_stack_bonus *a)
{
	int	tmp;

	if (a->top && a->top->next)
	{
		tmp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = tmp;
	}
}

void	sb_bonus(t_stack_bonus *b)
{
	int	tmp;

	if (b->top && b->top->next)
	{
		tmp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = tmp;
	}
}

void	help_sa_bonus(t_stack_bonus *a)
{
	int	tmp;

	if (a->top && a->top->next)
	{
		tmp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = tmp;
	}
}

void	help_sb_bonus(t_stack_bonus *b)
{
	int	tmp;

	if (b->top && b->top->next)
	{
		tmp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = tmp;
	}
}

void	ss_bonus(t_stack_bonus *a, t_stack_bonus *b)
{
	help_sa_bonus(a);
	help_sb_bonus(b);
}
