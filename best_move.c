// #include "push_swap.h"

// int calcul(t_stack *a, t_stack *b)
// {
//     t_node *cur;
//     cur = a->top;
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

typedef struct s_move
{
    int b_index;  // index of element in stack B
    int a_index;  // index of element in stack A
} t_move;

// Function to create a new node
t_node *new_node(int data)
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node to the top of the stack
void push(t_stack *stack, int data)
{
    t_node *node = new_node(data);
    if (!node)
        return;
    node->next = stack->top;
    stack->top = node;
}

// Function to find the index of an element in stack A
int get_index_a(t_stack *stack, t_node *node)
{
    int index = 0;
    t_node *current = stack->top;
    while (current)
    {
        if (current == node)
            return index;
        current = current->next;
        index++;
    }
    return -1;  // If the node is not found
}

// Function to find the target index for an element in stack B in stack A
int get_target_index(t_stack *stack_a, int b_value)
{
    t_node *current = stack_a->top;
    t_node *prev = NULL;
    while (current)
    {
        if (prev && prev->data < b_value && current->data > b_value)
            return get_index_a(stack_a, current);  // Found the right spot
        prev = current;
        current = current->next;
    }
    // Handle wrap-around case (insert at the beginning)
    return 0;  // Before the smallest element in stack A
}

// Function to backup indices of elements in stack B
void backup_indices(t_stack *stack_a, t_stack *stack_b, t_move *moves)
{
    t_node *current_b = stack_b->top;
    int b_index = 0;

    // Traverse stack B and calculate target indices in stack A
    while (current_b)
    {
        moves[b_index].b_index = b_index;
        moves[b_index].a_index = get_target_index(stack_a, current_b->data);
        current_b = current_b->next;
        b_index++;
    }
}

// Helper function to print the moves
void print_moves(t_move *moves, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("B Index: %d, A Index: %d\n", moves[i].b_index, moves[i].a_index);
    }
}

int main()
{
    t_stack stack_a = {NULL};
    t_stack stack_b = {NULL};
    
    // Example stack A: [15 → 1 → 5 → 8 → 10 → (back to 15)]
    push(&stack_a, 10);
    push(&stack_a, 8);
    push(&stack_a, 5);
    push(&stack_a, 1);
    push(&stack_a, 15);
    
    // Example stack B: [7 → 0 → 12]
    push(&stack_b, 12);
    push(&stack_b, 0);
    push(&stack_b, 7);

    // Backup indices and calculate target positions
    int stack_b_size = 3;  // Number of elements in stack B
    t_move moves[stack_b_size];
    backup_indices(&stack_a, &stack_b, moves);

    // Print the backed-up indices and target positions
    print_moves(moves, stack_b_size);

    return 0;
}
