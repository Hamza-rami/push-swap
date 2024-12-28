#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    if (is_empty(b))
        return ;
    push(a, pop(b));
}