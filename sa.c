#include "push_swap.h"

void sa(t_stack *a)
{
    int tmp;
    if (a->top && a->top->next)
    {
        tmp = a->top->data;
        a->top->data = a->top->next->data;
        a->top->next->data = tmp;
    }
}
