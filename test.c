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
void aff(t_node *stack_a, t_node *stack_b, int size)
{
	printf("------Start-----\n");
	while (size)
	{
		if (stack_a)
		{
			printf("%3d| \t", stack_a->data);
			// printf("------> %d",stack_a->indx);
			stack_a = stack_a->next;
		}
		else
		{
			printf("  |   \t");
		}
		if (stack_b)
		{
			printf("%3d| ", stack_b->data);
			// printf("------> %d",stack_b->flag);
			stack_b = stack_b->next;
		}
		size--;
		printf("\n");
	}
	printf("-\t  \t-\na\t  \tb\n");
	printf("------End-----\n");
}

int main(int argc, char const *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_calc *calc_list = NULL;
	t_calc *min_calc;

    stack_a = init_stack();
    stack_b = init_stack();
    parse_and_push(argc, argv, stack_a);

    if (if_sorted(stack_a)) {
        free_stack(stack_a);
        free_stack(stack_b);
        exit(0);
    }

    if (get_size(stack_a) <= 3) {
        sort_three(stack_a);
    } else if (get_size(stack_a) <= 5) {
        sort_than_5(stack_a, stack_b);
    } else {
        part_stack(stack_a, stack_b);
    	print_stack(stack_a);
		printf("stack b ------\n");
        print_stack(stack_b);
		while (!is_empty(stack_b))
		{
        	calculate_indices(stack_a, stack_b, &calc_list);
        t_calc *current = calc_list;
        while (current) {
            printf("Index A: %d, Index B: %d, Min Moves: %d\n",
                   current->index_a, current->index_b, current->min_move);
            current = current->next;
        }
        	min_move(stack_a, stack_b, calc_list);
			min_calc = find_min_move(calc_list);
			best_fun(stack_a, stack_b, min_calc);
			print_stack(stack_a);
			printf("stack b ------\n");
        	print_stack(stack_b);
			// break;
		}
    }

    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}
