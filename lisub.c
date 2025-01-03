#include "push_swap.h"

#include <stdlib.h>

int get_size(t_stack *stack) {
    t_node *current; 
    int size;

    size = 0;
    current = stack->top;
    while (current) {
        size++;
        current = current->next;
    }
    return (size);
}

int *ft_change(t_stack *stack, int size) {
    int *array;
    t_node *current;
    int i;

    if (size == 0)
        return (NULL);
    array = malloc(size * sizeof(int));
    if (!array)
        return (NULL);
    current = stack->top;
    i = 0;
    while (current) {
        array[i++] = current->data;
        current = current->next;
    }
    return (array);
}

void init_arrays(int *lis_length, int *prev, int size) {
    int i;

    i = 0;
    while (i < size) {
        lis_length[i] = 1;
        prev[i] = -1;
        i++;
    }
}

void find_lis_length(int *arr, int *lis_length, int *prev, int size) {
    int i;
    int j;

    i = 1;
    while (i < size) {
        j = 0;
        while (j < i) {
            if (arr[j] < arr[i] && lis_length[j] + 1 > lis_length[i]) {
                lis_length[i] = lis_length[j] + 1;
                prev[i] = j;
            }
            j++;
        }
        i++;
    }
}

int get_max_index(int *lis_length, int size) {
    int max_index;
    int i;

    max_index = 0;
    i = 1;
    while (i < size) {
        if (lis_length[i] > lis_length[max_index])
            max_index = i;
        i++;
    }
    return (max_index);
}

int *build_lis_indices(int *prev, int *lis_length, int max_index) {
    int *lis_indices;
    int idx;

    lis_indices = malloc(lis_length[max_index] * sizeof(int));
    if (!lis_indices)
        return (NULL);
    idx = lis_length[max_index] - 1;
    while (max_index != -1) {
        lis_indices[idx--] = max_index;
        max_index = prev[max_index];
    }
    return (lis_indices);
}

int *find_lis_indices(t_stack *stack) {
    int size;
    int *arr;
    int *lis_length;
    int *prev;
    int max_index;
    int *lis_indices;

    size = get_size(stack);
    if (size == 0)
        return (NULL);
    arr = ft_change(stack, size);
    if (!arr)
        return (NULL);
    lis_length = malloc(size * sizeof(int));
    prev = malloc(size * sizeof(int));
    if (!lis_length || !prev) {
        free(arr);
        free(lis_length);
        free(prev);
        return (NULL);
    }
    init_arrays(lis_length, prev, size);
    find_lis_length(arr, lis_length, prev, size);
    max_index = get_max_index(lis_length, size);
    lis_indices = build_lis_indices(prev, lis_length, max_index);
    free(arr);
    free(lis_length);
    free(prev);
    return (lis_indices);
}


