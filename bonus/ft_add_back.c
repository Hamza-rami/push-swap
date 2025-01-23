/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:29:12 by hrami             #+#    #+#             */
/*   Updated: 2025/01/22 18:09:02 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node_bonus	*ft_add_back_list(t_node_bonus **list, t_node_bonus *new_node)
{
	t_node_bonus	*tmp;

	if (!list || !new_node)
		return (NULL);
	if (!*list)
	{
		*list = new_node;
		return (*list);
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (*list);
}

t_node_bonus	*ft_lst_new(char *str)
{
	t_node_bonus	*new_node;

	new_node = malloc(sizeof(t_node_bonus));
	if (!new_node)
		return (NULL);
	new_node->str = str;
	new_node->next = NULL;
	return (new_node);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_sorted(t_stack_bonus *stack)
{
	t_node_stack	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_list(t_node_bonus *list)
{
	t_node_bonus	*temp;

	while (list)
	{
		temp = list->next;
		free(list->str);
		free(list);
		list = temp;
	}
}
