/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lisub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:05:37 by hrami             #+#    #+#             */
/*   Updated: 2025/01/14 10:53:53 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_arrays(int *lis_length, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis_length[i] = 1;
		prev[i] = -1;
		i++;
	}
}

void	find_lis_length(int *arr, int *lis_length, int *prev, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis_length[j] + 1 > lis_length[i])
			{
				lis_length[i] = lis_length[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	get_max_index(int *lis_length, int size)
{
	int	max_index;
	int	i;

	max_index = 0;
	i = 1;
	while (i < size)
	{
		if (lis_length[i] > lis_length[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	*build_lis_indices(int *prev, int *lis_length, int max_index)
{
	int	*lis_indices;
	int	idx;

	lis_indices = malloc(lis_length[max_index] * sizeof(int));
	if (!lis_indices)
		return (NULL);
	idx = lis_length[max_index] - 1;
	while (max_index != -1)
	{
		lis_indices[idx--] = max_index;
		max_index = prev[max_index];
	}
	return (lis_indices);
}

int	*find_lis_indices(t_stack *stack, int *index)
{
	int	*arr;
	int	*lis_length;
	int	*prev;
	int	max_index;
	int	*lis_indices;

	if (get_size(stack) == 0)
		return (NULL);
	arr = ft_change(stack, get_size(stack));
	lis_length = malloc(get_size(stack) * sizeof(int));
	prev = malloc(get_size(stack) * sizeof(int));
	if (!lis_length || !prev || !arr)
		return (free(arr), free(lis_length), free(prev), NULL);
	init_arrays(lis_length, prev, get_size(stack));
	find_lis_length(arr, lis_length, prev, get_size(stack));
	max_index = get_max_index(lis_length, get_size(stack));
	*index = lis_length[max_index];
	lis_indices = build_lis_indices(prev, lis_length, max_index);
	free(arr);
	free(lis_length);
	free(prev);
	return (lis_indices);
}
