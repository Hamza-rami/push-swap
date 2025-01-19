#include "push_swap_bonus.h"

int	check_move(char *str)
{
    if (ft_strcmp(str, "sa\n"))
		return (1);
    else if (ft_strcmp(str, "sb\n"))
		return (1);
    else if (ft_strcmp(str, "ss\n"))
		return (1);
    else if (ft_strcmp(str, "ra\n"))
		return (1);
    else if (ft_strcmp(str, "rb\n"))
		return (1);
    else if (ft_strcmp(str, "rr\n"))
		return (1);
    else if (ft_strcmp(str, "pa\n"))
		return (1);
    else if (ft_strcmp(str, "pb\n"))
		return (1);
    else if (ft_strcmp(str, "rra\n"))
		return (1);
    else if (ft_strcmp(str, "rrb\n"))
		return (1);
    else if (ft_strcmp(str, "rrr\n"))
		return (1);
	else
		return (0);
}
