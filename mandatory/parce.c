/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:30 by hrami             #+#    #+#             */
/*   Updated: 2025/01/22 11:07:35 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_duplicate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->data == second->data)
			{
				manage_a(0);
				manage_b(0);
				write(2, "Error\n", 6);
				exit(1);
			}
			second = second->next;
		}
		first = first->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*next;

	while (stack->top != NULL)
	{
		next = stack->top->next;
		free(stack->top);
		stack->top = next;
	}
}

int	is_valid_number(char **split, t_stack *stack)
{
	int		i;
	int		value;

	i = 0;
	while (split[i])
	{
		value = ft_atoi(split[i], split);
		add_back(stack, value);
		i++;
	}
	free_split(split);
	is_duplicate(stack);
	return (0);
}

void	check_isemty(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

void	parse_and_push(int argc, char *argv[], t_stack *stack)
{
	char	*joined;
	char	**split;

	check_isemty(argv);
	joined = ft_join_arg(argc, argv);
	split = ft_split(joined, ' ');
	free(joined);
	is_valid_number(split, stack);
}
