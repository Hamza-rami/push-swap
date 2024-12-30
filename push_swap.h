
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
void pa(t_stack *b, t_stack *a);
void rr(t_stack *a, t_stack *b);
void rrr(t_stack *a, t_stack *b);
void ss(t_stack *a, t_stack *b);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);

#endif