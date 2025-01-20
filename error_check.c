#include "push_swap.h"

void	error_exit(void)
{
	ft_putmsg_fd("Error\n", 2);
	exit(1);
	return ;
}

int	arg_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	char_error(char *argv[])
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (!arg_is_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	dup_error(t_stack *stack)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i <= stack->i_top)
	{
		j = i + 1;
		while (j <= stack->i_top)
		{
			if (stack->arr[j] == stack->arr[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
