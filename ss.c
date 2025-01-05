/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:50:08 by hrami             #+#    #+#             */
/*   Updated: 2025/01/04 11:50:09 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void help_sa(t_stack *a)
{
    int tmp;
    if (a->top && a->top->next)
    {
        tmp = a->top->data;
        a->top->data = a->top->next->data;
        a->top->next->data = tmp;
    }
}

void help_sb(t_stack *b)
{
    int tmp;
    if (b->top && b->top->next)
    {
        tmp = b->top->data;
        b->top->data = b->top->next->data;
        b->top->next->data = tmp;
    }
}

void ss(t_stack *a, t_stack *b)
{
    help_sa(a);
    help_sa(b);
    write(1, "ss\n", 3);
}