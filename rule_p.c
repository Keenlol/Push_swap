#include "push_swap.h"

void	p_operation(t_stack *stack_to, t_stack *stack_from)
{
	ssize_t	i;

	stack_to->i_top++;
	stack_to->arr[stack_to->i_top] = stack_from->arr[stack_from->i_top];
	stack_from->arr[stack_from->i_top] = 0;
	stack_from->i_top--;
	if (stack_to->arr[stack_to->i_top] > stack_to->greatest)
		stack_to->greatest = stack_to->arr[stack_to->i_top];
	i = 0;
	stack_from->greatest = stack_from->arr[i];
	while (i < stack_from->i_top)
	{
		if (stack_from->arr[i] > stack_from->greatest)
			stack_from->greatest = stack_from->arr[i];
		i++;
	}
}

int		p(t_stack *stack_a, t_stack *stack_b, char mode)
{
	t_stack	*stack_from;
	t_stack	*stack_to;

	printf("p%c\n", mode);
	if (mode == 'a')
	{
		stack_from = stack_b;
		stack_to = stack_a;
	}
	else if (mode == 'b')
	{
		stack_from = stack_a;
		stack_to = stack_b;
	}
	if (stack_from->i_top < 0)
		return (2);
    p_operation(stack_to, stack_from);
	return (2);
}
