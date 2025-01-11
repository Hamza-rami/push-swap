#include "push_swap.h"
int get_index_a(t_stack *stack_a, int b_value)
{
    t_node *current;
    int index = 0;
    int small_index = 0;
    int largest_index = 0;
    int small_value = current->data;
    int largest_value = current->data;

    while (current)
    {
        if (current->data < small_value)
        {
            small_value = current->data;
            small_index = index;
        }
        if (current->data > largest_value)
        {
            largest_value = current->data;
            largest_index = index;
        }
        if(current->data < b_value && current->next->data > b_value)
            return(index);
        current = current->next;
        index++;
    }
    if (b_value < small_value)
        return small_index;
    if (b_value > largest_value)
        return largest_index + 1;
}

void calculate_indices(t_stack *stack_a, t_stack *stack_b, t_calc **calc_list)
{
    t_node *cur_b;
    int index_b;
    t_calc *new_calc;
    t_calc *temp;

    cur_b = stack_b->top;
    index_b = 0;
    while (cur_b)
    {
        new_calc = malloc(sizeof(t_calc));
        if(!new_calc)
            return;
        new_calc->index_b = index_b;
        new_calc->index_b = get_index_a(stack_a, cur_b->data);
        new_calc->min_move = -1;
        new_calc->next = NULL;
        
        if(*calc_list == NULL)
            *calc_list = new_calc;
        else
        {
            temp = *calc_list;
            while (temp->next)
                temp = temp->next;
            temp->next = new_calc;
        }
        cur_b = cur_b->next;
        index_b++;
    }
}
