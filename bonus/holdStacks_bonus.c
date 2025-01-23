/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holdStacks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:05:35 by hrami             #+#    #+#             */
/*   Updated: 2025/01/22 18:06:04 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack_bonus	*manage_a(int check)
{
	static t_stack_bonus	*a;

	if (check == 1)
		a = init_stack_bonus();
	else
	{
		free_stack_bonus(a);
		free(a);
		a = NULL;
	}
	return (a);
}

t_stack_bonus	*manage_b(int check)
{
	static t_stack_bonus	*b;

	if (check == 1)
		b = init_stack_bonus();
	else
	{
		free_stack_bonus(b);
		free(b);
		b = NULL;
	}
	return (b);
}
