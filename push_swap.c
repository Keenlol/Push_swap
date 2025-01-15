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
	printf("\ni = %ld\n", i);
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

// int		is_solved(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (stack_a->i_top == 0)
// 		return (1);
// 	while()
// }

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	use("sa pb pb", stack_a, stack_b);
	while (stack_a->i_top > 1)
	{
		rotate(stack_a, stack_b, stack_a->arr[stack_a->i_top]);
		use("pb", stack_a, stack_b);
	}
}


