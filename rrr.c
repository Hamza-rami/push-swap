/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:04:56 by hrami             #+#    #+#             */
/*   Updated: 2025/01/04 12:04:57 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void help_rra(t_stack *a)
{
    t_node *prev;
    t_node *curren;

    if (a->top && a->top->next)
    {
        curren = a->top;
        while (curren->next)
        {
            prev = curren;
            curren = curren->next;
        }
        prev->next = NULL;
        curren->next = a->top;
        a->top = curren;
    }
}

void help_rrb(t_stack *b)
{
    t_node *prev;
    t_node *curren;

    if (b->top && b->top->next)
    {
        curren = b->top;
        while (curren->next)
        {
            prev = curren;
            curren = curren->next;
        }
        prev->next = NULL;
        curren->next = b->top;
        b->top = curren;
    }
}

void rrr(t_stack *a, t_stack *b)
{
    help_rra(a);
    help_rrb(b);
    write(1, "rrr\n", 4);
}