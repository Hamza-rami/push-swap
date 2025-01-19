#include "push_swap_bonus.h"

void	add_back_stack(t_stack *stack, int value)
{
	t_node	*temp;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
		return ;
	}
	temp = stack->top;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}