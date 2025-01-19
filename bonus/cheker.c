#include "get_next_line.h"
#include "push_swap_bonus.h"

void print_error()
{
    write(1, "Error\n", 6);
    exit(1);
}
int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_node_bonus *list;
    char *arr;

    stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		exit(1);
    parse_and_push(argc, argv, stack_a);
    arr = get_next_line(0);
    while (arr != NULL)
    {
        if (check_move(arr) == 0)
            print_error();
        ft_add_back(&list, ft_lst_new(arr));
        arr = get_next_line(0);
    }
    return (0);
}
