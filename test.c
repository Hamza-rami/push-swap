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
	t_stack *stack;
	int *arr;
	int i;

	stack = init_stack();
	ft_join_arg(argc, argv);
	parse_and_push(argc, argv, stack);
	arr = find_lis_indices(stack);
	print_stack(stack);
	i = 0;
		printf("%d", arr[i]);
		printf("%d", arr[1]);
		printf("%d", arr[2]);

	// while (arr[i])
	// {
	// }
	return 0;
}
