#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node_bonus
{
	char *str;
	struct s_node_bonus *next;
} t_node_bonus;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

int		check_move(char *str);
int		ft_strcmp(char *s1, char *s2);
t_node_bonus    *ft_add_back(t_node_bonus **list, t_node_bonus *new_node);
void    free_list(t_node_bonus *list);
t_node_bonus    *ft_lst_new(char *str);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	rra(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
int		ft_atoi(char const *str);
char	**ft_split(char const *s, char c);
void	parse_and_push(int argc, char *argv[], t_stack *stack);
char	*ft_join_arg(int argc, char *argv[]);
int	is_empty(t_stack *stack);
int	pop(t_stack *stack);
void	push(t_stack *stack, int value);
t_stack	*init_stack(void);
void	add_back_stack(t_stack *stack, int value);


#endif