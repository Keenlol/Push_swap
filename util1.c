#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;

	i = stack_a->i_top;
	if (stack_b->i_top > i)
		i = stack_b->i_top;
	ft_putmsg_fd("---------------------\n", 1);
	while (i >= 0)
	{
		if (stack_a->i_top >= i)
			ft_putnbr_fd(stack_a->arr[i], 1);
		else
			write(1, " ", 1);
		write(1, " ", 1);
		if (stack_b->i_top >= i)
			ft_putnbr_fd(stack_b->arr[i], 1);
		else
			write(1, " ", 1);
		write(1, "\n", 1);
		i--;
	}
	ft_putmsg_fd("_ _\na b\n", 1);
}

void	create_stack_a(t_stack *stack_a, char *argv[], ssize_t size)
{
	int		*arr;
	int		i;

	stack_a->i_max = size - 1;
	stack_a->i_top = size - 1;
	arr = malloc(size * sizeof(int));
	i = 1;
	stack_a->greatest = -2147483647;
	while (argv[i])
	{
		arr[i - 1] = ft_atoi(argv[size - i + 1]);
		if (arr[i - 1] > stack_a->greatest)
			stack_a->greatest = arr[i - 1];
		i++;
	}
	stack_a->arr = arr;
}

void	create_stack_b(t_stack *stack_b, ssize_t size)
{
	int		*arr;

	stack_b->i_max = size - 1;
	stack_b->i_top = -1;
	arr = malloc(size * sizeof(int));
	stack_b->arr = arr;
	stack_b->greatest = -2147483647;
}

void	use(char *command, t_stack *stack_a, t_stack *stack_b)
{
	while (*command)
	{
		if (*command == ' ')
			command++;
		else if (*command == 's')
			command += s(stack_a, stack_b, *(command + 1));
		else if (*command == 'p')
			command += p(stack_a, stack_b, *(command + 1));
		else if (*command == 'r' && (*(command + 2) == ' '
				|| *(command + 2) == '\0'))
			command += r(stack_a, stack_b, *(command + 1));
		else if (*command == 'r' && *(command + 1) == 'r')
			command += rr(stack_a, stack_b, *(command + 2));
	}
}

void	find_good_spot_b(ssize_t *i_b, t_stack *stack_b, int num)
{
	*i_b = stack_b->i_top;
	while (!valid(stack_b, *i_b, num))
		(*i_b)--;
}
