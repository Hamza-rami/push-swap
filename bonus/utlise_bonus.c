/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlise_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:27 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 12:30:39 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	add_back_bonus(t_stack_bonus *stack, int value)
{
	t_node_stack	*temp;
	t_node_stack	*new_node;

	new_node = malloc(sizeof(t_node_stack));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
		return ;
	}
	temp = stack->top;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}
