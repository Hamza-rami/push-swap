/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:28:59 by hrami             #+#    #+#             */
/*   Updated: 2025/01/22 23:28:39 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_error(t_node_bonus *list)
{
	manage_a(0);
	manage_b(0);
	free_list(list);
	write(1, "Error\n", 6);
}

void	print_ok_ko(t_stack_bonus *a, t_stack_bonus *b)
{
	if (is_sorted(a) && is_empty_bonus(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	checker_help(t_node_bonus **list)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (check_move(line) == 0)
		{
			free(line);
			print_error(*list);
			free(list);
			exit(1);
		}
		ft_add_back_list(list, ft_lst_new(line));
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack_bonus	*stack_a;
	t_stack_bonus	*stack_b;
	t_node_bonus	*list;
	t_node_bonus	*temp;

	list = NULL;
	stack_a = manage_a(1);
	stack_b = manage_b(1);
	if (!stack_a || !stack_b)
		exit(1);
	parse_and_push_bonus(argc, argv, stack_a);
	checker_help(&list);
	temp = list;
	while (temp)
	{
		apply_move(temp->str, stack_a, stack_b);
		temp = temp->next;
	}
	print_ok_ko(stack_a, stack_b);
	free_list(list);
	manage_a(0);
	manage_b(0);
	return (0);
}
