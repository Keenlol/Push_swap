#include "push_swap.h"

void	rr_operation(t_stack *stack)
{
	int		tmp;
	int		i;

	tmp = stack->arr[0];
	i = 0;
	while (i < stack->i_top)
		stack->arr[i++] = stack->arr[i + 1];
	stack->arr[stack->i_top] = tmp;
}

int		rr(t_stack *stack_a, t_stack *stack_b, char mode)
{
	t_stack	*stack_main;

	printf("rr%c\n", mode);
	if (mode == 'a')
		rr_operation(stack_a);
	else if (mode == 'b')
		rr_operation(stack_b);
	else if (mode == 'r')
	{
		rr_operation(stack_a);
		rr_operation(stack_b);
	}
	return (3);
}
