/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:30 by hrami             #+#    #+#             */
/*   Updated: 2025/01/04 13:27:54 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_node	*first;
	t_node	*second;

	i = 0;
	while (split[i])
	{
		push(stack, ft_atoi(split[i]));
		free(split[i]);
		i++;
	}
	free(split);
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
	return (0);
}

void	parse_and_push(int argc, char const *argv[], t_stack *stack)
{
	char	*joined;
	char	**split;

	joined = ft_join_arg(argc, argv);
	split = ft_split(joined, ' ');
	free(joined);
	is_valid_number(split, stack);
}
