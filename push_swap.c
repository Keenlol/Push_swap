#include "push_swap.h"

int		valid(t_stack *stack_b, ssize_t i, int num)
{
	if (stack_b->i_top == 1)
	if (i == stack_b->i_top && 
		stack_b->arr[stack_b->i_top] <= num <= stack_b->arr[0]
		)
		return (1);
	if (0 <= i < stack_b->i_top && 
		stack_b->arr[i-1] <= num <= stack_b->arr[i+1])
		return (1);
	return (0);
}

void	rotate(t_stack *stack_a, t_stack *stack_b, int a_num_top)
{
	ssize_t	i;
	char	*command;

	if (valid(stack_b, stack_b->i_top, a_num_top))
		return;
	i = 0;
	while (1)
	{
		if (valid(stack_b, i, a_num_top))
		{
			command = "rb";
			break;
		}
		if (valid(stack_b, stack_b->i_top - 1 - i, a_num_top))
		{
			command = "rrb";
			break;
		}
		i++;
	}
	while (i > 0)
	{
		printf("\n -- %s\n", command);
		use(command, stack_a, stack_b);
		i--;
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	use("pb", stack_a, stack_b);
	use("pb", stack_a, stack_b);

	rotate(stack_a, stack_b, stack_a->arr[stack_a->i_top]);
}


