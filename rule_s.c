#include "push_swap.h"

void	s_operation(t_stack *stack)
{
	int		tmp;

	if (stack->i_top < 1)
		return ;
	tmp = stack->arr[stack->i_top];
	stack->arr[stack->i_top] = stack->arr[stack->i_top - 1];
	stack->arr[stack->i_top - 1] = tmp;
}

int	s(t_stack *stack_a, t_stack *stack_b, char mode)
{
	write(1, "s", 1);
	write(1, &mode, 1);
	write(1, "\n", 1);
	if (mode == 'a')
		s_operation(stack_a);
	else if (mode == 'b')
		s_operation(stack_b);
	else if (mode == 's')
	{
		s_operation(stack_a);
		s_operation(stack_b);
	}
	return (2);
}
