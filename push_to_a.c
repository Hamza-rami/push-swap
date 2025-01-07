/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:17 by hrami             #+#    #+#             */
/*   Updated: 2025/01/07 12:53:27 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ret_a(t_stack *a, int position)
{
	int	size;

	size = get_size(a);
	if (position <= size / 2)
		while (position--)
			rra(a);
	else
		while (position++ < size)
			ra(a);
}

void	push_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		element;
	int		position;
	int		size;
	int		tmp;

	while (b->top)
	{
		element = b->top->data;
		cur = a->top;
		position = 0;
		size = get_size(a);
		while (cur && cur->data < element)
		{
			cur = cur->next;
			position++;
		}
		tmp = position;
		if (position <= size / 2)
			while (position--)
				ra(a);
		else
			while (position++ < size)
				rra(a);
		pa(a, b);
		ret_a(a, tmp);
	}
}