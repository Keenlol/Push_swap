#include "push_swap.h"

int		valid(t_stack *stack_b, ssize_t i, int num)
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
	if (num_below == num_above && num != num_above)
		return (0);
	if ((num_below <= num && num <= num_above) ||
		(num_below == stack_b->greatest && 
		(num <= num_above || stack_b->greatest <= num)))
		return (1);
	return (0);
}

void	rotate(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;
	int		from_num_top;

	i = stack_b->i_top;
	while (!valid(stack_b, i, stack_a->arr[stack_a->i_top]))
		i--;
	rotate_to(stack_a, stack_b, "b", i);
}

int		a_is_sorted(t_stack *stack_a)
{
	ssize_t	i;
	ssize_t	count;
	int		num_below;

	i = 0;
	while (stack_a->arr[i] != stack_a->greatest)
		i++;
	num_below = stack_a->arr[i];
	count = stack_a->i_top;
	while (count > 0)
	{
		i = (i + 1) % (stack_a->i_top + 1);
		if (stack_a->arr[i] > num_below)
			return (0);
		num_below = stack_a->arr[i];
		count--;
	}
	return (1);
}

void	b_self_correct(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;
	int		num_above;

	i = 0;
	if (stack_b->i_top == 0)
		return;
	num_above = stack_b->arr[i+1];
	while (i < stack_b->i_top)
	{
		if (stack_b->arr[i] == stack_b->greatest &&
			stack_b->arr[i] > num_above)
			break;
		i++;
		num_above = stack_b->arr[i+1];
	}
	rotate_to(stack_a, stack_b, "b", i);
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

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;
	
	while (stack_b->i_top >= 0)
	{
		while (stack_b->arr[stack_b->i_top] < stack_a->arr[0] && 
				stack_a->arr[0] != stack_a->greatest)
			use("rra", stack_a, stack_b);
		use("pa", stack_a, stack_b);
	}
	i = 0;
	while (stack_a->arr[i] != stack_a->greatest)
		i++;
	if (i - 1 >= 0)
		rotate_to(stack_a, stack_b, "a", i - 1);
}

void	a_self_correct(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;

	i = 0;
	if (stack_a->i_top <= 0)
		return;
	while (stack_a->arr[i] != stack_a->greatest)
		i++;
	i--;
	if (stack_a->greatest >= stack_b->greatest)
		i++;
	if (i != -1)
		rotate_to(stack_a, stack_b, "a", i);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;

	while (!a_is_sorted(stack_a))
	{
		rotate(stack_a, stack_b);
		use("pb", stack_a, stack_b);
	}
	b_self_correct(stack_a, stack_b);
	a_self_correct(stack_a, stack_b);
	push_back(stack_a, stack_b);
}


