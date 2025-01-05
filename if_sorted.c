/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:46 by hrami             #+#    #+#             */
/*   Updated: 2025/01/04 12:28:04 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_size(t_stack *stack)
{
	t_node	*current;
	int		size;

	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
