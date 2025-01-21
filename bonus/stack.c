/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:50:02 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 13:01:29 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack_bonus	*init_stack_bonus(void)
{
	t_stack_bonus	*stack;

	stack = malloc(sizeof(t_stack_bonus));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void	push_bonus(t_stack_bonus *stack, int value)
{
	t_node_stack	*new_node;

	new_node = malloc(sizeof(t_node_stack));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

int	pop_bonus(t_stack_bonus *stack)
{
	int				value;
	t_node_stack	*tmp;

	tmp = stack->top;
	value = tmp->data;
	stack->top = tmp->next;
	free(tmp);
	return (value);
}

int	is_empty_bonus(t_stack_bonus *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}
