/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:30 by hrami             #+#    #+#             */
/*   Updated: 2025/01/16 16:12:55 by hrami            ###   ########.fr       */
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
				free_stack(stack);
				write(2, "Error\n", 6);
				exit(0);
			}
			second = second->next;
		}
		first = first->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	is_valid_number(char **split, t_stack *stack)
{
	int		i;

	i = 0;
	while (split[i])
	{
		add_back(stack, ft_atoi(split[i]));
		free(split[i]);
		i++;
	}
	free(split);
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
