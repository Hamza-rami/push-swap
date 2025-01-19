/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:54:07 by hrami             #+#    #+#             */
/*   Updated: 2025/01/18 15:47:22 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_sorted(t_stack *stack_a)
{
	int	idx;

	idx = check_min_index(stack_a->top);
	if (idx > get_size(stack_a) / 2)
	{
		while (idx++ < get_size(stack_a))
			rra(stack_a);
	}
	else
	{
		while (idx-- > 0)
			ra(stack_a);
	}
}

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_calc	*calc_list;
	t_calc	*min_calc;

	part_stack(stack_a, stack_b);
	while (!is_empty(stack_b))
	{
		calc_list = calculate_indices(stack_a, stack_b);
		min_move(stack_a, stack_b, calc_list);
		min_calc = find_min_move(calc_list);
		best_fun(stack_a, stack_b, min_calc);
		free_calc_list(calc_list);
	}
	if (!if_sorted(stack_a))
		rotate_to_sorted(stack_a);
}

void	handle_small_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_than_5(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		exit(1);
	parse_and_push(argc, argv, stack_a);
	if (if_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(1);
	}
	if (get_size(stack_a) <= 5)
		handle_small_stacks(stack_a, stack_b, get_size(stack_a));
	else
		sort_large_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
