/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:34:14 by hrami             #+#    #+#             */
/*   Updated: 2025/01/14 10:50:40 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_extremes(t_node *current, t_extremes *ext)
{
	int	index;

	index = 0;
	ext->smallest = current->data;
	ext->largest = current->data;
	ext->small_index = 0;
	ext->large_index = 0;
	while (current)
	{
		if (current->data < ext->smallest)
		{
			ext->smallest = current->data;
			ext->small_index = index;
		}
		if (current->data > ext->largest)
		{
			ext->largest = current->data;
			ext->large_index = index;
		}
		current = current->next;
		index++;
	}
}

int	get_index_a(t_stack *stack_a, int b_value)
{
	t_node		*current;
	t_extremes	ext;
	int			index;

	current = stack_a->top;
	find_extremes(current, &ext);
	current = stack_a->top;
	index = 0;
	while (current->next)
	{
		if (current->data < b_value && current->next->data > b_value)
			return (index + 1);
		current = current->next;
		index++;
	}
	if (b_value < ext.smallest)
		return (ext.small_index);
	if (b_value > ext.largest)
		return (ext.large_index + 1);
	return (-1);
}

void	add_calc(t_calc **calc_list, t_calc *new_calc)
{
	t_calc	*temp;

	if (*calc_list == NULL)
		*calc_list = new_calc;
	else
	{
		temp = *calc_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new_calc;
	}
}

t_calc	*calculate_indices(t_stack *stack_a, t_stack *stack_b)
{
	t_calc	*calc_list;
	t_node	*cur_b;
	int		index_b;
	t_calc	*new_calc;
	t_calc	*temp;

	cur_b = stack_b->top;
	calc_list = NULL;
	index_b = 0;
	while (cur_b)
	{
		new_calc = malloc(sizeof(t_calc));
		if (!new_calc)
			return (NULL);
		new_calc->index_b = index_b;
		new_calc->index_a = get_index_a(stack_a, cur_b->data);
		new_calc->min_move = -1;
		new_calc->next = NULL;
		add_calc(&calc_list, new_calc);
		cur_b = cur_b->next;
		index_b++;
	}
	return (calc_list);
}

void	min_move(t_stack *a, t_stack *b, t_calc *calc_list)
{
	t_calc	*cur;
	int		two_up;
	int		two_down;
	int		up_down;
	int		down_up;

	cur = calc_list;
	while (cur)
	{
		two_up = max(cur->index_a, cur->index_b);
		two_down = max(get_size(a) - cur->index_a, get_size(b) - cur->index_b);
		up_down = cur->index_a + get_size(b) - cur->index_b;
		down_up = get_size(a) - cur->index_a + cur->index_b;
		cur->min_move = min(two_up, min(two_down, min(up_down, down_up)));
		cur = cur->next;
	}
}
