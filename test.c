#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
    {
        printf("Stack is empty.\n");
        return;
    }

    current = stack->top;
    printf("Stack elements: ");
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    t_stack *stack;

    stack = init_stack();
    parse_and_push(argc, argv, stack);
    print_stack(stack);
    int i = if_sorted(stack);
    printf("%d", i);
    return 0;
}
