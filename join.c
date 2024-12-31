#include "push_swap.h"

static char	*ft_strcpy(char *dest, char const *src)
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

char	*ft_strdup(const char *src)
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

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	arr = malloc(i + j + 1);
	if (arr == NULL)
		return (NULL);
	ft_strcpy(arr, s1);
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

char *ft_join_arg(int argc, char const *argv[])
{
    char *str = ft_strdup("");
    int i = 1;

    while (i < argc)
    {
        str = ft_strjoin(str, argv[i]);
        str = ft_strjoin(str, " ");
        i++;
    }
    return (str);
}