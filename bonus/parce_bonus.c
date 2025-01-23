/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:19 by hrami             #+#    #+#             */
/*   Updated: 2025/01/22 13:45:11 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_duplicate_bonus(t_stack_bonus *stack)
{
	t_node_stack	*first;
	t_node_stack	*second;

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

void	free_stack_bonus(t_stack_bonus *stack)
{
	t_node_stack	*current;
	t_node_stack	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

static int	is_valid_number(char **split, t_stack_bonus *stack)
{
	int		i;

	i = 0;
	while (split[i])
	{
		add_back_bonus(stack, ft_atoi_bonus(split[i], split));
		i++;
	}
	free_split_bonus(split);
	is_duplicate_bonus(stack);
	return (0);
}

void	check_isemty_bonus(char **argv)
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

void	parse_and_push_bonus(int argc, char *argv[], t_stack_bonus *stack)
{
	char	*joined;
	char	**split;

	check_isemty_bonus(argv);
	joined = ft_join_arg_bonus(argc, argv);
	split = ft_split_bonus(joined, ' ');
	free(joined);
	is_valid_number(split, stack);
}
