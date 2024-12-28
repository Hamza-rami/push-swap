#include "push_swap.h"

void rra(t_stack *a)
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