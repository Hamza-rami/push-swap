/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:07 by hrami             #+#    #+#             */
/*   Updated: 2025/01/04 12:05:08 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void help_ra(t_stack *a)
{
    t_node *tmp;
    t_node *curren;

    if (a->top && a->top->next)
    {
        tmp = a->top;
        a->top = a->top->next;
        curren = a->top;
        while (curren->next)
        {
            curren = curren->next;
        }
        curren->next = tmp;
        tmp->next = NULL;
    }
}

void help_rb(t_stack *b)
{
    t_node *tmp;
    t_node *curren;

    if (b->top && b->top->next)
    {
        tmp = b->top;
        b->top = b->top->next;
        curren = b->top;
        while (curren->next)
        {
            curren = curren->next;
        }
        curren->next = tmp;
        tmp->next = NULL;
    }
}

void rr(t_stack *a, t_stack *b)
{
    help_ra(a);
    help_rb(b);
    write(1, "rr\n", 3);
}