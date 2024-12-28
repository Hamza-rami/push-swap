#include "push_swap.h"
void ft_print(t_stack *a)
{
    t_node *temp = a->top;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;       
    }
    
}

int main()
{
    t_stack *a = init_stack();

    t_stack *tmp;
    t_stack *tmp1;


    push(a, 9);
    push(a, 6);
    push(a, 3);
    printf("Before sa:\n");
    ft_print(a);
  
    rrb(a);

    printf("\nafter sa:\n");
    ft_print(a);
    return 0;

}