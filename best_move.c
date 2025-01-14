/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:47 by hrami             #+#    #+#             */
/*   Updated: 2025/01/13 12:26:10 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_two_up(t_stack *a, t_stack *b, t_calc *calc)
{
	int	len_a;
	int	len_b;

	len_a = calc->index_a;
	len_b = calc->index_b;
	while (len_a > 0 && len_b > 0)
	{
		rr(a, b);
		len_a--;
		len_b--;
	}
	while (len_a > 0)
	{
		ra(a);
		len_a--;
	}
	while (len_b > 0)
	{
		rb(b);
		len_b--;
	}
	pa(a, b);
}

void	f_two_down(t_stack *a, t_stack *b, t_calc *calc)
{
	int	len_a;
	int	len_b;

	len_a = get_size(a) - calc->index_a;
	len_b = get_size(b) - calc->index_b;
	while (len_a > 0 && len_b > 0)
	{
		rrr(a, b);
		len_a--;
		len_b--;
	}
	while (len_a > 0)
	{
		rra(a);
		len_a--;
	}
	while (len_b > 0)
	{
		rrb(b);
		len_b--;
	}
	pa(a, b);
}

void	f_up_down(t_stack *a, t_stack *b, t_calc *calc)
{
	int	len_a;
	int	len_b;

	len_a = calc->index_a;
	len_b = get_size(b) - calc->index_b;
	while (len_a > 0)
	{
		ra(a);
		len_a--;
	}
	while (len_b > 0)
	{
		rrb(b);
		len_b--;
	}
	pa(a, b);
}

void	f_down_up(t_stack *a, t_stack *b, t_calc *calc)
{
	int	len_a;
	int	len_b;

	len_a = get_size(a) - calc->index_a;
	len_b = calc->index_b;
	while (len_b > 0)
	{
		rb(b);
		len_b--;
	}
	while (len_a > 0)
	{
		rra(a);
		len_a--;
	}
	pa(a, b);
}

void	best_fun(t_stack *a, t_stack *b, t_calc *calc)
{
	int	two_up;
	int	two_down;
	int	up_down;
	int	down_up;

	two_up = MAX(calc->index_a, calc->index_b);
	two_down = MAX(get_size(a) - calc->index_a, get_size(b) - calc->index_b);
	up_down = calc->index_a + get_size(b) - calc->index_b;
	down_up = get_size(a) - calc->index_a + calc->index_b;
	if (two_up == calc->min_move)
		f_two_up(a, b, calc);
	else if (two_down == calc->min_move)
		f_two_down(a, b, calc);
	else if (up_down == calc->min_move)
		f_up_down(a, b, calc);
	else
		f_down_up(a, b, calc);
}
