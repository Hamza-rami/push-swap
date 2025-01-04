
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node {
    int data;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_stack *init_stack(void);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
int is_empty(t_stack *stack);
void sa(t_stack *a);
void sb(t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rrb(t_stack *b);
void rra(t_stack *a);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *b, t_stack *a);
void rr(t_stack *a, t_stack *b);
void rrr(t_stack *a, t_stack *b);
void ss(t_stack *a, t_stack *b);
char *ft_join_arg(int argc, char const *argv[]);
char **ft_split(char const *s, char c);
int	ft_atoi(char const *str);
void parse_and_push(int argc, char const *argv[], t_stack *stack);
int if_sorted(t_stack *stack);
int *find_lis_indices(t_stack *stack , int *index);
int get_size(t_stack *stack);
void *part_stack(t_stack *a, t_stack *b);

#endif