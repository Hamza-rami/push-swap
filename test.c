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
	int *arr;

	stack_a = init_stack();
	stack_b = init_stack();
	ft_join_arg(argc, argv);
	parse_and_push(argc, argv, stack_a);
	part_stack(stack_a, stack_b);
	// push the elements of stack_b to stack_a ()
	// 4 check with a => 1 ra 3 ra pb => (2 * ra <= stack_a_size / 2 then rra ra time else ra stack_a_size - 2 * ra + 1)
	print_stack(stack_a);
	printf("-----------------------------\n");
	print_stack(stack_b);
		// printf("%d", arr[0]);
		// printf("%d", arr[1]);
	return 0;
}
