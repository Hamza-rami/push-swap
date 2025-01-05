/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:17 by hrami             #+#    #+#             */
/*   Updated: 2025/01/05 11:11:47 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ret_a(t_stack *a, int position)
// {
// 	int	size;

// 	size = get_size(a);
// 	if (position <= size / 2)
// 		while (position--)
// 			rra(a);
// 	else
// 		while (position++ < size)
// 			ra(a);
// }

// void	push_b_to_a(t_stack *a, t_stack *b)
// {
// 	t_node	*cur;
// 	int		element;
// 	int		position;
// 	int		size;
// 	int		tmp;

// 	while (b->top)
// 	{
// 		element = b->top->data;
// 		cur = a->top;
// 		position = 0;
// 		size = get_size(a);
// 		while (cur && cur->data < element)
// 		{
// 			cur = cur->next;
// 			position++;
// 		}
// 		tmp = position;
// 		if (position <= size / 2)
// 			while (position--)
// 				ra(a);
// 		else
// 			while (position++ < size)
// 				rra(a);
// 		pa(a, b);
// 		ret_a(a, tmp);
// 	}
// }

int calculate_rotations(int position, int size) {
    if (position <= size / 2)
        return position; // Forward rotations
    return position - size; // Reverse rotations
}

int find_best_rotation(t_stack *a, int element) {
    t_node *cur = a->top;
    int position = 0;

    while (cur) {
        if (cur->data > element)
            break;
        cur = cur->next;
        position++;
    }
    return position;
}

int stack_size(t_stack *stack) {
    t_node *cur = stack->top;
    int size = 0;

    while (cur) {
        cur = cur->next;
        size++;
    }
    return size;
}

void align_stack(t_stack *stack, int position, void (*rotate)(t_stack *), void (*reverse_rotate)(t_stack *)) {
    int size = stack_size(stack);
    int rotations = calculate_rotations(position, size);

    if (rotations >= 0) {
        while (rotations--)
            rotate(stack);
    } else {
        while (rotations++)
            reverse_rotate(stack);
    }
}

void push_b_to_a(t_stack *a, t_stack *b) {
    while (b->top) {
        int element = b->top->data;
        int position_a = 0;
        int size_a = stack_size(a);

        t_node *cur = a->top;
        while (cur) {
            if (cur->data > element)
                break;
            cur = cur->next;
            position_a++;
        }

        // Align stack A to the insertion position
        align_stack(a, position_a, ra, rra);

        // Push the top of stack B to stack A
        pa(a, b);

        // Optional: Align stack A back to its sorted order
        if (a->top->data > a->top->next->data) {
            ra(a);
        }
    }
}

