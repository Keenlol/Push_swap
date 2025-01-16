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
	if ((num_below <= num && num <= num_above) ||
		(num_below == stack_b->greatest && 
		(num <= num_above || stack_b->greatest <= num)))
		return (1);
	return (0);
}

void	rotate(t_stack *stack_a, t_stack *stack_b, int a_num_top)
{
	ssize_t	i;
	char	*command;

	i = stack_b->i_top;
	while (!valid(stack_b, i, stack_a->arr[stack_a->i_top]))
		i--;
	if (i >= stack_b->i_top / 2)
	{
		i = stack_b->i_top - i;
		while (i-- > 0)
			use("rb", stack_a, stack_b);
	}
	else
	{
		while (i-- >= 0)
			use("rrb", stack_a, stack_b);
	}
}

int		is_sorted(t_stack *stack, ssize_t i_start, ssize_t i_end, char mode)
{
	int		num_prev;
	ssize_t	count;
	ssize_t	i;

	count = i_end - i_start;
	if (i_start > i_end)
		count = stack->i_top - i_start + i_end + 1;
	i = i_start + 1;
	num_prev = stack->arr[i_start];
	printf("count = %ld\n",count);
	while (count > 0)
	{
		if (i > stack->i_top)
			i = 0;
		printf("comp %d with %d\n", stack->arr[i], num_prev);
		if (mode == 'a' && stack->arr[i] < num_prev)
				return (0);
		if (mode == 'd' && stack->arr[i] > num_prev)
				return (0);
		num_prev = stack->arr[i];
		i++;
		count--;
	}
	return (1);
}

// void	push_back(t_stack *stack_a, t_stack *stack_b)
// {

// }

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	// use("sa pb pb", stack_a, stack_b);
	// while (!a_is_sorted(stack_a))
	// {
	// 	rotate(stack_a, stack_b, stack_a->arr[stack_a->i_top]);
	// 	use("pb", stack_a, stack_b);
	// }
	// while (stack_b->i_top > -1)
	// {
	// 	rotate(stack_b, stack_a, stack_b->arr[stack_b->i_top]);
	// 	use("pa", stack_a, stack_b);
	// }
	if (is_sorted(stack_a, 2, 1, 'd'))
		printf("sorted!");
}


