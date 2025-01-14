/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:03 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:45:51 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
