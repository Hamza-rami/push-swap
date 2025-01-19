/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:00 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:46:12 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
