/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:08 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 12:30:09 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_bonus(t_stack_bonus *a, t_stack_bonus *b)
{
	if (is_empty_bonus(b))
		return ;
	push_bonus(a, pop_bonus(b));
}

void	pb_bonus(t_stack_bonus *b, t_stack_bonus *a)
{
	if (is_empty_bonus(a))
		return ;
	push_bonus(b, pop_bonus(a));
}
