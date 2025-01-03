#include "push_swap.h"

static void	ft_skip(char const *str, int *s, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if ((str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i] == '-')
			*s *= -1;
		(*i)++;
	}
}

int	ft_atoi(char const *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	ft_skip(str, &s, &i);

	while (str[i])
	{
        if (str[i] < '0' || str[i] > '9') 
        {
            write(2, "Error\n", 6);
            exit(0);
        }
        r = r * 10 + (str[i] - '0');
        if (r * s > 2147483647 || r * s < -2147483648)
		{
            write(2, "Error\n", 6);
            exit(0);			
		}
        i++;
    }
	return (r * s);
}
