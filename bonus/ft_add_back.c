#include "push_swap_bonus.h"

t_node_bonus    *ft_add_back_list(t_node_bonus **list, t_node_bonus *new_node)
{
    t_node_bonus *tmp;

    if (!list || !new_node)
	    return (NULL);
    if (!*list)
        *list = new_node;
    else
        tmp = *list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    return (*list);
}
t_node_bonus *ft_lst_new(char *str)
{
    t_node_bonus *new_node;

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

int	if_sorted(t_stack *stack)
{
	t_node	*current;

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
	while (list)
	{
		free(list);
		list = list->next;
	}
}