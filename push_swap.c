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

	printf("%d <= %d <= %d\n", num_below, num, num_above);

	if ((num_below <= num && num <= num_above) ||
		(num_below == stack_b->greatest && 
		(num <= num_above || stack_b->greatest <= num)))
		return (1);
	return (0);
	// if (i == i_b_top)
	// {
	// 	if (stack_b->arr[i_b_top] <= num && num <= stack_b->arr[0])
	// 		return (1);
	// 	if (num >= stack_b->greatest && stack_b->arr[i_b_top] == stack_b->greatest)
	// 		return (1);
	// 	return (0);
	// }
	// else
	// {
	// 	if (stack_b->arr[i] <= num && num <= stack_b->arr[i+1])
	// 		return (1);
	// 	return (0);
	// }
	// return (0);
}

void	rotate(t_stack *stack_a, t_stack *stack_b, int a_num_top)
{
	ssize_t	i;
	char	*command;

	i = stack_b->i_top;
	while (!valid(stack_b, i, stack_a->arr[stack_a->i_top]))
		i--;
	printf("\ni = %ld\n", i);


}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	use("sa pb pb", stack_a, stack_b);
	rotate(stack_a, stack_b, stack_a->arr[stack_a->i_top]);
}


