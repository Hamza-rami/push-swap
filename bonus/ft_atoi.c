/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:53 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 15:05:14 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	void	ft_skip(char *str, int *s, int *i)
{	
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if ((str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			*s *= -1;
		(*i)++;
	}
	if (str[*i] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}		
}

int	ft_atoi_bonus(char *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	ft_skip(str, &s, &i);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		r = r * 10 + (str[i] - '0');
		if (r * s > 2147483647 || r * s < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (r * s);
}
