/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:50:18 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:50:19 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_index(t_node *a)
{
	t_node	*tmp;
	int		max;
	int		max_idx;
	int		current_idx;

	tmp = a;
	max = tmp->data;
	max_idx = 0;
	current_idx = 0;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			max_idx = current_idx;
		}
		tmp = tmp->next;
		current_idx++;
	}
	return (max_idx);
}

int	check_min_index(t_node *a)
{
	t_node	*tmp;
	int		min;
	int		min_idx;
	int		current_idx;

	tmp = a;
	min = tmp->data;
	min_idx = 0;
	current_idx = 0;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_idx = current_idx;
		}
		tmp = tmp->next;
		current_idx++;
	}
	return (min_idx);
}

void	sort_three(t_stack *a)
{
	int		idx;
	t_node	*tmp;

	tmp = a->top;
	idx = check_max_index(a->top);
	if (idx == 0)
		ra(a);
	if (idx == 1)
		rra(a);
	if (a->top->data > a->top->next->data)
		sa(a);
}

void	sort_than_5(t_stack *a, t_stack *b)
{
	int	size;
	int	idx;

	size = get_size(a);
	while (size > 3)
	{
		idx = check_min_index(a->top);
		if (idx > size / 2)
		{
			while (idx++ < size)
				rra(a);
		}
		else
		{
			while (idx-- > 0)
				ra(a);
		}
		pb(b, a);
		size--;
	}
	sort_three(a);
	while (!is_empty(b))
		pa(a, b);
}
