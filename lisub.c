#include "push_swap.h"


int *find_lis_indices(int *arr, int size, int *lis_size) 
{
    if (size == 0) {
        *lis_size = 0;
        return NULL;
    }

    int *lis_length = malloc(size * sizeof(int));
    int *prev = malloc(size * sizeof(int));
    int i, j;

    for (i = 0; i < size; i++) {
        lis_length[i] = 1;
        prev[i] = -1;
    }

    for (i = 1; i < size; i++) {
        for (j = 0; j < i; j++) {
            if (arr[j] < arr[i] && lis_length[j] + 1 > lis_length[i]) {
                lis_length[i] = lis_length[j] + 1;
                prev[i] = j;
            }
        }
    }

    int max_index = 0;
    for (i = 1; i < size; i++) {
        if (lis_length[i] > lis_length[max_index]) {
            max_index = i;
        }
    }

    *lis_size = lis_length[max_index];
    int *lis_indices = malloc((*lis_size) * sizeof(int));
    int idx = *lis_size - 1;
    while (max_index != -1) {
        lis_indices[idx--] = max_index;
        max_index = prev[max_index];
    }

    free(lis_length);
    free(prev);

    return lis_indices;
}
