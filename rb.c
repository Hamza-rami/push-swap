/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:11 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:44:59 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*curren;

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
	write(1, "rb\n", 3);
}
