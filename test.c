// #include "push_swap.h"

// void print_stack(t_stack *stack)
// {
// 	t_node *current;

// 	if (!stack || !stack->top)
// 	{
// 		printf("Stack is empty.\n");
// 		return;
// 	}

// 	current = stack->top;
// 	printf("Stack elements: ");
// 	while (current)
// 	{
// 		printf("%d ", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// }
// void aff(t_node *stack_a, t_node *stack_b, int size)
// {
// 	printf("------Start-----\n");
// 	while (size)
// 	{
// 		if (stack_a)
// 		{
// 			printf("%3d| \t", stack_a->data);
// 			// printf("------> %d",stack_a->indx);
// 			stack_a = stack_a->next;
// 		}
// 		else
// 		{
// 			printf("  |   \t");
// 		}
// 		if (stack_b)
// 		{
// 			printf("%3d| ", stack_b->data);
// 			// printf("------> %d",stack_b->flag);
// 			stack_b = stack_b->next;
// 		}
// 		size--;
// 		printf("\n");
// 	}
// 	printf("-\t  \t-\na\t  \tb\n");
// 	printf("------End-----\n");
// }
// int main(int argc, char const *argv[])
// {
// 	t_stack *stack_a;
// 	t_stack *stack_b;
// 	int *arr;

// 	stack_a = init_stack();
// 	stack_b = init_stack();
// 	parse_and_push(argc, argv, stack_a);
// 	if (if_sorted(stack_a)) {
// 	    free_stack(stack_a);
// 	    free_stack(stack_b);
// 	    exit(0);
// 	}
// 	if (get_size(stack_a) <= 3)
// 	{
// 		sort_three(stack_a);
// 	}
// 	else if (get_size(stack_a) <= 5)
// 	{
// 		//aff(stack_a->top, stack_b->top, max(get_size(stack_a), get_size(stack_b)));
// 		sort_than_5(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		part_stack(stack_a, stack_b);
// 		aff(stack_a->top, stack_b->top, max(get_size(stack_a), get_size(stack_b)));
// 		push_b_to_a_circular(stack_a, stack_b);
// 		aff(stack_a->top, stack_b->top, max(get_size(stack_a), get_size(stack_b)));
// 	}
// 	print_stack(stack_a);
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	return 0;
// }