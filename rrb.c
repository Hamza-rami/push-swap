#include "push_swap.h"

void rrb(t_stack *b)
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