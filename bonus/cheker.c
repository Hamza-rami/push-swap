/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:28:59 by hrami             #+#    #+#             */
/*   Updated: 2025/01/21 09:53:14 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap_bonus.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stack_bonus	*stack_a;
	t_stack_bonus	*stack_b;
	t_node_bonus	*list;
	t_node_bonus	*temp;
	char			*line;

	list = NULL;
	stack_a = init_stack_bonus();
	stack_b = init_stack_bonus();
	if (!stack_a || !stack_b)
		exit(1);
	parse_and_push_bonus(argc, argv, stack_a);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (check_move(line) == 0)
		{
			free(line);
			free_list(list);
			print_error();
		}
		ft_add_back_list(&list, ft_lst_new(line));
		line = get_next_line(0);
	}
	temp = list;
	while (temp)
	{
		apply_move(temp->str, stack_a, stack_b);
		temp = temp->next;
	}
	if (is_sorted(stack_a) && is_empty_bonus(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(list);
	free_stack_bonus(stack_a);
	free_stack_bonus(stack_b);
	return (0);
}
