#include "push_swap.h"

void pa(t_stack *b, t_stack *a)
{
    if (is_empty(a))
        return ;
    push(b, pop(a));
}