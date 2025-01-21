/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:29:04 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 13:03:25 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	apply_move(char *str, t_stack_bonus *a, t_stack_bonus *b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa_bonus(a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb_bonus(b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss_bonus(a, b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra_bonus(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb_bonus(b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr_bonus(a, b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa_bonus(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb_bonus(b, a);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra_bonus(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb_bonus(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr_bonus(a, b);
	else
		return ;
}
