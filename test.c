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
int main() 
{
    int arr[] = {1, 3, 7, 5, 9, 4, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int lis_size;

    int *lis_indices = find_lis_indices(arr, size, &lis_size);

    printf("LIS Indices: ");
    for (int i = 0; i < lis_size; i++) {
        printf("%d ", lis_indices[i]);
    }
    printf("\n");

    printf("LIS Elements: ");
    for (int i = 0; i < lis_size; i++) {
        printf("%d ", arr[lis_indices[i]]);
    }
    printf("\n");

    free(lis_indices);
    return 0;
}