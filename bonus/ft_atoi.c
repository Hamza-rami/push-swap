/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:53 by hrami             #+#    #+#             */
/*   Updated: 2025/01/22 18:11:22 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_split_bonus(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_error_bonus(char **split)
{
	manage_a(0);
	manage_b(0);
	free_split_bonus(split);
	write(2, "Error\n", 6);
	exit(1);
}

static	void	ft_skip(char *str, int *s, int *i, char **split)
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
		print_error_bonus(split);
	}		
}

int	ft_atoi_bonus(char *str, char **split)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	ft_skip(str, &s, &i, split);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error_bonus(split);
		r = r * 10 + (str[i] - '0');
		if (r * s > 2147483647 || r * s < -2147483648)
			print_error_bonus(split);
		i++;
	}
	return (r * s);
}
