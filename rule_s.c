#include "push_swap.h"

void    s_operation(t_stack *stack)
{
	int		tmp;

	if (stack->i_top < 1)
		return ;
	tmp = stack->arr[stack->i_top];
	stack->arr[stack->i_top] = stack->arr[stack->i_top - 1];
	stack->arr[stack->i_top - 1] = tmp;
}

int		s(t_stack *stack_a, t_stack *stack_b, char mode)
{
	t_stack	*stack_main;
	int		i;

	printf("s%c\n", mode);
	i = 1;
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
