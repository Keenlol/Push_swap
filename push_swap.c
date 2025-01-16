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

void	rotate(t_stack *stack_from, t_stack *stack_to, char *mode)
{
	ssize_t	i;
	char	*command;
	int		from_num_top;

	command = malloc(4 * sizeof(char));
	i = stack_to->i_top;
	while (!valid(stack_to, i, stack_from->arr[stack_from->i_top], mode[0]))
		i--;
	if (i >= stack_to->i_top / 2)
	{
		strcpy(command, "r");
		strcat(command, mode);
		i = stack_to->i_top - i - 1;
	}
	else
	{
		strcpy(command, "rr");
		strcat(command, mode);
	}
	while (i-- >= 0)
		use(command, stack_from, stack_to);
	free(command);
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

// void	push_back(t_stack *stack_a, t_stack *stack_b)
// {

// }

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	use("pb pb", stack_a, stack_b);
	while (!a_is_sorted(stack_a))
	{
		rotate(stack_a, stack_b,"b");
		use("pb", stack_a, stack_b);
	}
	// while (stack_b->i_top > -1)
	// {
	// 	rotate(stack_b, stack_a, 'a');
	// 	use("pa", stack_a, stack_b);
	// }
}


