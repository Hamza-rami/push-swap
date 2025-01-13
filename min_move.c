#include "push_swap.h"
int get_index_a(t_stack *stack_a, int b_value)
{
	t_node *current = stack_a->top;
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
		if (current->next && current->data < b_value && current->next->data > b_value)
			return (index + 1);
		current = current->next;
		index++;
	}
	if (b_value < small_value)
		return small_index;
	if (b_value > largest_value)
		return (largest_index + 1);
	return -1;
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
		if (!new_calc)
			return;
		new_calc->index_b = index_b;
		new_calc->index_a = get_index_a(stack_a, cur_b->data);
		new_calc->min_move = -1;
		new_calc->next = NULL;
		if (*calc_list == NULL)
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


void min_move(t_stack *a, t_stack *b, t_calc *calc_list)
{
	t_calc *cur;
	int size_a;
	int size_b;
	int index_a;
	int index_b;
	int two_up;
	int two_down;
	int up_down;
	int down_up;

	cur = calc_list;
	size_a = get_size(a);
	size_b = get_size(b);
	while (cur)
	{
		index_a = cur->index_a;
		index_b = cur->index_b;
		two_up = MAX(index_a, index_b);
		two_down = MAX(size_a - index_a, size_b - index_b);
		up_down = index_a + size_b - index_b;
		down_up = size_a - index_a + index_b;
		cur->min_move = MIN(two_up, MIN(two_down, MIN(up_down, down_up)));
		cur = cur->next;
	}
}

t_calc *find_min_move(t_calc *calc_list)
{
	t_calc *cur = calc_list;
	t_calc *min_move_node = cur;
	int min_move = cur->min_move;

	while (cur)
	{
		if (cur->min_move < min_move)
		{
			min_move = cur->min_move;
			min_move_node = cur;
		}
		cur = cur->next;
	}
	return (min_move_node);
}

