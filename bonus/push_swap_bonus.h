/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:22 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 12:34:35 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node_bonus
{
	char				*str;
	struct s_node_bonus	*next;
}	t_node_bonus;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node_stack;

typedef struct s_stack
{
	t_node_stack	*top;
}	t_stack_bonus;

int				check_move(char *str);
int				ft_strcmp(char *s1, char *s2);
t_node_bonus	*ft_add_back_list(t_node_bonus **list, t_node_bonus *new_node);
void			free_list(t_node_bonus *list);
t_node_bonus	*ft_lst_new(char *str);
void			sa_bonus(t_stack_bonus *a);
void			sb_bonus(t_stack_bonus *b);
void			ra_bonus(t_stack_bonus *a);
void			rb_bonus(t_stack_bonus *b);
void			rrb_bonus(t_stack_bonus *b);
void			rra_bonus(t_stack_bonus *a);
void			rrr_bonus(t_stack_bonus *a, t_stack_bonus *b);
void			pa_bonus(t_stack_bonus *a, t_stack_bonus *b);
void			pb_bonus(t_stack_bonus *b, t_stack_bonus *a);
void			rr_bonus(t_stack_bonus *a, t_stack_bonus *b);
void			ss_bonus(t_stack_bonus *a, t_stack_bonus *b);
int				is_empty_bonus(t_stack_bonus *stack);
int				pop_bonus(t_stack_bonus *stack);
void			push_bonus(t_stack_bonus *stack, int value);
char			**ft_split_bonus(char const *s, char c);
int				ft_atoi_bonus(char *str);
t_stack_bonus	*init_stack_bonus(void);
void			free_stack_bonus(t_stack_bonus *stack);
void			parse_and_push_bonus(int argc, char *argv[],
					t_stack_bonus *stack);
char			*ft_join_arg_bonus(int argc, char *argv[]);
void			add_back_bonus(t_stack_bonus *stack, int value);
void			apply_move(char *str, t_stack_bonus *a, t_stack_bonus *b);
int				is_sorted(t_stack_bonus *stack);

#endif