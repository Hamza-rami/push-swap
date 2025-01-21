/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:30:05 by hrami             #+#    #+#             */
/*   Updated: 2025/01/20 13:03:08 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	char	*ft_strcpy_bonus(char *dest, char const *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_bonus(const char *src)
{
	int		i;
	int		size;
	char	*str;

	size = 0;
	i = 0;
	while (src[size])
	{
		size++;
	}
	str = malloc(size + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen_bonus(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_bonus(char *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen_bonus(s1);
	j = ft_strlen_bonus(s2);
	arr = malloc(i + j + 1);
	if (arr == NULL)
		return (free(s1), NULL);
	ft_strcpy_bonus(arr, s1);
	j = 0;
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	free(s1);
	return (arr);
}

char	*ft_join_arg_bonus(int argc, char *argv[])
{
	char	*str;
	int		i;

	str = ft_strdup_bonus("");
	i = 1;
	while (i < argc)
	{
		str = ft_strjoin_bonus(str, argv[i]);
		str = ft_strjoin_bonus(str, " ");
		i++;
	}
	return (str);
}