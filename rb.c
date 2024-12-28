#include "push_swap.h"

void rb(t_stack *b)
{
    t_node *tmp;
    t_node *curren;

    if (b->top && b->top->next)
    {
        tmp = b->top;
        b->top =  b->top->next;
        curren = b->top;
        while (curren->next)
        {
            curren = curren->next;
        }
        curren->next = tmp;
        tmp->next = NULL;
    }
}