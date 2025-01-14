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
    t_stack *stack_a;
    t_stack *stack_b;
    t_calc *calc_list;
	t_calc *min_calc;
	int idx;

    stack_a = init_stack();
    stack_b = init_stack();
    parse_and_push(argc, argv, stack_a);
    if (if_sorted(stack_a)) {
        free_stack(stack_a);
        free_stack(stack_b);
        exit(0);
    }
    if (get_size(stack_a) <= 3)
        sort_three(stack_a);
	else if (get_size(stack_a) <= 5)
        sort_than_5(stack_a, stack_b);
	else 
	{
        part_stack(stack_a, stack_b);
		while (!is_empty(stack_b))
		{
        	calc_list = calculate_indices(stack_a, stack_b);
        	min_move(stack_a, stack_b, calc_list);
			min_calc = find_min_move(calc_list);
			best_fun(stack_a, stack_b, min_calc);
		}
		idx = check_min_index(stack_a->top);
        if (idx > get_size(stack_a) / 2)
        {
            while (idx++ < get_size(stack_a))
                rra(stack_a);
        }
        else
        {
            while (idx-- > 0)
                ra(stack_a);
        }
    }
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}
