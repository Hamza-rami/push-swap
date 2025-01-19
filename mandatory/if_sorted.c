/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:46 by hrami             #+#    #+#             */
/*   Updated: 2025/01/15 13:15:51 by hrami            ###   ########.fr       */
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

void	add_back(t_stack *stack, int value)
{
	t_node	*temp;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
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

int	*ft_change(t_stack *stack, int size)
{
	int		*array;
	t_node	*current;
	int		i;

	if (size == 0)
		return (NULL);
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		array[i++] = current->data;
		current = current->next;
	}
	return (array);
}

t_calc	*find_min_move(t_calc *calc_list)
{
	t_calc	*cur;
	t_calc	*min_move_node;
	int		min_move;

	cur = calc_list;
	min_move_node = cur;
	min_move = cur->min_move;
	while (cur)
	{
		if (cur->min_move < min_move)
		{
			min_move = cur->min_move;
			min_move_node = cur;
		}
		cur = cur->next;
	}
	return (min_move_node);
}
