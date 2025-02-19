/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:29:07 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 12:32:14 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_move(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (1);
	else
		return (0);
}
