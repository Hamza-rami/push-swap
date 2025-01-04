#include "push_swap.h"

int if_in(int *arr, int index, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == index)
            return (1);
        i++;
    }
    return (0);
}

void *part_stack(t_stack *a, t_stack *b)
{
    int *arr;
    int my_index;
    int size;
    int size_index;

    arr = find_lis_indices(a, &size_index);
    if (!arr)
        return (NULL);
    size = get_size(a);
    my_index = 0;
    while (my_index < size)
    {
        if (if_in(arr, my_index, size_index))
            ra(a);
        else
            pb(b, a);
        my_index++;
    }
    free(arr);
    return (NULL);
}