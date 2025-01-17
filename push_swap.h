/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:21 by hrami             #+#    #+#             */
/*   Updated: 2025/01/17 14:55:38 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

typedef struct s_calc
{
	int				index_a;
	int				index_b;
	int				min_move;
	struct s_calc	*next;
}	t_calc;

typedef struct s_extremes
{
	int	smallest;
	int	small_index;
	int	largest;
	int	large_index;
}	t_extremes;

t_stack	*init_stack(void);
void	add_back(t_stack *stack, int value);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		is_empty(t_stack *stack);
void	free_stack(t_stack *stack);
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
char	*ft_join_arg(int argc, char *argv[]);
char	**ft_split(char const *s, char c);
int		ft_atoi(char const *str);
void	parse_and_push(int argc, char *argv[], t_stack *stack);
int		if_sorted(t_stack *stack);
int		*ft_change(t_stack *stack, int size);
int		*find_lis_indices(t_stack *stack, int *index);
int		get_size(t_stack *stack);
void	*part_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_than_5(t_stack *a, t_stack *b);
int		min(int a, int b);
int		max(int a, int b);
int		check_min_index(t_node *a);
void	min_move(t_stack *a, t_stack *b, t_calc *calc_list);
t_calc	*calculate_indices(t_stack *stack_a, t_stack *stack_b);
void	best_fun(t_stack *a, t_stack *b, t_calc *calc);
t_calc	*find_min_move(t_calc *calc_list);
void	free_calc_list(t_calc *calc_list);

#endif