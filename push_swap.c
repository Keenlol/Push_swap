#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	while (!a_is_sorted(stack_a))
	{
		rotate_b(stack_a, stack_b);
		use("pb", stack_a, stack_b);
	}
	b_self_correct(stack_a, stack_b);
	a_self_correct(stack_a, stack_b);
	push_back(stack_a, stack_b);
}

void	a_self_correct(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;

	i = 0;
	if (stack_a->i_top <= 0)
		return ;
	while (stack_a->arr[i] != stack_a->greatest)
		i++;
	i--;
	if (stack_a->greatest > stack_b->greatest)
		i++;
	if (i != -1)
		rotate_to(stack_a, stack_b, "a", i);
}

void	b_self_correct(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;
	int		num_above;

	i = 0;
	if (stack_b->i_top == 0)
		return ;
	num_above = stack_b->arr[i + 1];
	while (i < stack_b->i_top)
	{
		if (stack_b->arr[i] == stack_b->greatest
			&& stack_b->arr[i] > num_above)
			break ;
		i++;
		num_above = stack_b->arr[i + 1];
	}
	rotate_to(stack_a, stack_b, "b", i);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;

	while (stack_b->i_top >= 0)
	{
		while (stack_b->arr[stack_b->i_top] < stack_a->arr[0]
			&& stack_a->arr[0] != stack_a->greatest)
			use("rra", stack_a, stack_b);
		use("pa", stack_a, stack_b);
	}
	i = 0;
	while (stack_a->arr[i] != stack_a->greatest)
		i++;
	if (i - 1 >= 0)
		rotate_to(stack_a, stack_b, "a", i - 1);
}

int	a_is_sorted(t_stack *stack_a)
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
