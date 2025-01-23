/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holdStacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:09:28 by hrami             #+#    #+#             */
/*   Updated: 2025/01/22 11:35:02 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*manage_a(int check)
{
	static t_stack	*a;

	if (check == 1)
		a = init_stack();
	else
	{
		free_stack(a);
		free(a);
		a = NULL;
	}
	return (a);
}

t_stack	*manage_b(int check)
{
	static t_stack	*b;

	if (check == 1)
		b = init_stack();
	else
	{
		free_stack(b);
		free(b);
		b = NULL;
	}
	return (b);
}
