#include "push_swap.h"

void ra(t_stack *a)
{
    t_node *tmp;
    t_node *curren;

    if (a->top && a->top->next)
    {
        tmp = a->top;
        a->top =  a->top->next;
        curren = a->top;
        while (curren->next)
        {
            curren = curren->next;
        }
        curren->next = tmp;
        tmp->next = NULL;
    }
}