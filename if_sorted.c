#include "push_swap.h"

int if_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
        return (1);

    current = stack->top;
    while (current->next)
    {
        if (current->data > current->next->data)
            return (0);
        current = current->next;
    }
    return (1);
}
