/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:50:15 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:47:35 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->top && a->top->next)
	{
		tmp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = tmp;
	}
	write(1, "sa\n", 3);
}