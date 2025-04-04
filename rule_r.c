#include "push_swap.h"

void	r_operation(t_stack *stack)
{
	int		tmp;
	int		i;

	tmp = stack->arr[stack->i_top];
	i = stack->i_top;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = tmp;
}

int	r(t_stack *stack_a, t_stack *stack_b, char mode)
{
	write(1, "r", 1);
	write(1, &mode, 1);
	write(1, "\n", 1);
	if (mode == 'a')
		r_operation(stack_a);
	else if (mode == 'b')
		r_operation(stack_b);
	else if (mode == 'r')
	{
		r_operation(stack_a);
		r_operation(stack_b);
	}
	return (2);
}
