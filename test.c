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
// void a() {
// 	system("leaks a.out");

// }
int main(int argc, char const *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	int *arr;

	stack_a = init_stack();
	stack_b = init_stack();
	// atexit(a);
	// ft_join_arg(argc, argv);
	parse_and_push(argc, argv, stack_a);
	if (if_sorted(stack_a)) {
	    free_stack(stack_a);
	    free_stack(stack_b);
	    exit(0); // Exit if the stack is already sorted
	}
	part_stack(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	// 4 check with a => 1 ra 3 ra pb => (2 * ra <= stack_a_size / 2 then rra ra time else ra stack_a_size - 2 * ra + 1)
	// printf("-----------------------------\n");
	// system("leaks a.out");
	free_stack(stack_a);
	free_stack(stack_b);
	return 0;
}