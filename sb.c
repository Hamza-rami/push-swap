/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:50:12 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:47:55 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b)
{
	int	tmp;

	if (b->top && b->top->next)
	{
		tmp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = tmp;
	}
	write(1, "sb\n", 3);
}
