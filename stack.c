/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:50:02 by hrami             #+#    #+#             */
/*   Updated: 2025/01/04 13:20:53 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

int	pop(t_stack *stack)
{
	int	value;
	t_node	*tmp;

	tmp = stack->top;
	value = tmp->data;
	stack->top = tmp->next;
	free(tmp);
	return (value);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}
