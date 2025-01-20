#include "push_swap.h"

int	valid(t_stack *stack_b, ssize_t i, int num)
{
	ssize_t	i_b_top;
	int		num_below;
	int		num_above;

	i_b_top = stack_b->i_top;
	if (i == i_b_top)
		num_above = stack_b->arr[0];
	else
		num_above = stack_b->arr[i + 1];
	num_below = stack_b->arr[i];
	if ((num_below < num && num < num_above)
		|| (num_below == stack_b->greatest
			&& (num < num_above || stack_b->greatest < num)))
		return (1);
	return (0);
}

void	rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i_b;
	ssize_t	i_a;
	ssize_t	i_a_lowest_cost;
	ssize_t	cost;

	if (stack_b->i_top <= 0)
		return ;
	i_a_lowest_cost = stack_a->i_top;
	i_a = stack_a->i_top;
	while (i_a >= 0)
	{
		i_b = stack_b->i_top;
		while (!valid(stack_b, i_b, stack_a->arr[i_a]))
			i_b--;
		cost = cal_cost(stack_a->i_top, i_a, stack_b->i_top, i_b);
		if (cost < i_a_lowest_cost)
			i_a_lowest_cost = i_a;
		i_a--;
	}
	rotate_to(stack_a, stack_b, "a", i_a_lowest_cost);
	i_b = stack_b->i_top;
	while (!valid(stack_b, i_b, stack_a->arr[stack_a->i_top]))
		i_b--;
	rotate_to(stack_a, stack_b, "b", i_b);
}

void	rotate_to(t_stack *stack_a, t_stack *stack_b, char *m, ssize_t i_dst)
{
	char	*command;
	ssize_t	i_top;

	if (m[0] == 'a')
		i_top = stack_a->i_top;
	else if (m[0] == 'b')
		i_top = stack_b->i_top;
	command = malloc(4 * sizeof(char));
	if (i_dst >= i_top / 2)
	{
		ft_strcpy(command, "r");
		ft_strcat(command, m);
		i_dst = i_top - i_dst - 1;
	}
	else
	{
		ft_strcpy(command, "rr");
		ft_strcat(command, m);
	}
	while (i_dst-- >= 0)
		use(command, stack_a, stack_b);
	free(command);
}

ssize_t	cal_cost(ssize_t i_atop, ssize_t i_a, ssize_t i_btop, ssize_t i_b)
{
	ssize_t	cost_b;
	ssize_t	cost_a;

	if (i_btop <= 0)
		return (0);
	if (i_b >= i_btop / 2)
		cost_b = i_btop - i_b;
	else
		cost_b = i_b + 1;
	if (i_a >= i_atop / 2)
		cost_a = i_atop - i_a;
	else
		cost_a = i_a + 1;
	return (cost_a + cost_b);
}
