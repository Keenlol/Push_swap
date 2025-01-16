#include "push_swap.h"

int		valid(t_stack *stack_b, ssize_t i, int num, char mode)
{
	ssize_t	i_b_top;
	int		num_below;
	int		num_above;

	i_b_top = stack_b->i_top;
	if (i == i_b_top)
		num_above = stack_b->arr[0];
	else
		num_above = stack_b->arr[i+1];
	num_below = stack_b->arr[i];
	if (mode == 'b' &&
		((num_below <= num && num <= num_above) ||
		(num_below == stack_b->greatest && 
		(num <= num_above || stack_b->greatest <= num))))
		return (1);
	if (mode == 'a' &&
		((num_below >= num && num >= num_above) ||
		(num_above == stack_b->greatest && 
		(num <= num_below || stack_b->greatest <= num))))
		return (1);
	return (0);
}

void	rotate(t_stack *stack_a, t_stack *stack_b, char *mode)
{
	ssize_t	i;
	int		from_num_top;

	i = stack_b->i_top;
	while (!valid(stack_b, i, stack_a->arr[stack_a->i_top], mode[0]))
		i--;
	rotate_to(stack_a, stack_b, mode, i);
}

int		a_is_sorted(t_stack *stack_a)
{
	int		num_below;
	ssize_t	i;
	i = 0;

	num_below = stack_a->arr[stack_a->i_top];
	while (i <= stack_a->i_top)
	{
		if (stack_a->arr[i] != stack_a->greatest)
		{
			if (stack_a->arr[i] > num_below)
				return (0);
		}
		num_below = stack_a->arr[i];
		i++;
	}
	return (1);
}

void	b_self_correct(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;
	char	*command;

	i = 0;
	while (stack_b->arr[i] != stack_b->greatest)
		i++;
	if (i >= stack_b->i_top / 2)
	{
		command = "rb";
		i = stack_b->i_top - i - 1;
	}
	else
		command = "rrb";
	while (i-- >= 0)
		use(command, stack_a, stack_b);
}

void	rotate_to(t_stack *stack_a, t_stack *stack_b, char *mode, ssize_t i_dest)
{
	char	*command;
	ssize_t	i_top;

	if (mode[0] == 'a')
		i_top = stack_a->i_top;
	else if (mode[0] == 'b')
		i_top = stack_b->i_top;
	command = malloc(4 * sizeof(char));
	if (i_dest >= i_top / 2)
	{
		strcpy(command, "r");
		strcat(command, mode);
		i_dest = i_top - i_dest - 1;
	}
	else
	{
		strcpy(command, "rr");
		strcat(command, mode);
	}
	while (i_dest-- >= 0)
		use(command, stack_a, stack_b);
	free(command);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int		*func;

	use("pb pb", stack_a, stack_b);
	while (!a_is_sorted(stack_a))
	{
		rotate(stack_a, stack_b,"b");
		use("pb", stack_a, stack_b);
	}
	print_stacks(stack_a, stack_b);
	b_self_correct(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	while (stack_b->i_top >= 0)
	{
		rotate(stack_a, stack_b, "a");
		print_stacks(stack_a, stack_b);
		use("pa", stack_a, stack_b);
	}
}


