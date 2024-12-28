#include "push_swap.h"

void sb(t_stack *b)
{
    int tmp;
    if (b->top && b->top->next)
    {
        tmp = b->top->data;
        b->top->data = b->top->next->data;
        b->top->next->data = tmp;
    }
}
