/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:14 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:44:37 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*curren;

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
	write(1, "ra\n", 3);
}
