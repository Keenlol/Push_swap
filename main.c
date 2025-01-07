#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stack
{
	ssize_t	i_top;
	ssize_t	i_max;
	int		*arr;		
}				t_stack;



void    print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;

	i = stack_a->i_top;
	if (stack_b->i_top > i)
		i = stack_b->i_top;
	printf("---------------------\n");
	while (i >= 0)
	{
		if (stack_a->i_top >= i)
			printf("%d ", stack_a->arr[i]);
		else
			printf("  ");
		if (stack_b->i_top >= i)
			printf("%d\n", stack_b->arr[i]);
		else
			printf(" \n");
		i--;
	}
	printf("_ _\na b\n");
}

void	create_stack_a(t_stack *stack_a, char *argv[], ssize_t size)
{
	int		*arr;
	int		i;

	stack_a->i_max = size - 1;
	stack_a->i_top = size - 1;
	arr = malloc(size * sizeof(int));
	i = 1;
	while (argv[i])
	{
		arr[i-1] = atoi(argv[i]);
		i++;
	}
	stack_a->arr = arr;
}

void	create_stack_b(t_stack *stack_b, ssize_t size)
{
	int		*arr;

	stack_b->i_max = size - 1;
	stack_b->i_top = - 1;
	arr = malloc(size * sizeof(int));
	stack_b->arr = arr;
}

void	s(t_stack *stack_a, t_stack *stack_b, char mode)
{
	int		tmp;
	t_stack	*stack_main;
	int		i;

	printf("s%c\n", mode);
	i = 1;
	if (mode == 'a')
		stack_main = stack_a;
	else if (mode == 'b')
		stack_main = stack_b;
	else if (mode == 's')
	{
		stack_main = stack_a;
		i = 2;
	}
	while (i-- >= 1)
	{	
		if (stack_main->i_top < 1)
			return ;
		tmp = stack_main->arr[stack_main->i_top];
		stack_main->arr[stack_main->i_top] = stack_main->arr[stack_main->i_top - 1];
		stack_main->arr[stack_main->i_top - 1] = tmp;
		stack_main = stack_b;
	}
}

void	p(t_stack *stack_a, t_stack *stack_b, char mode)
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
		return ;
	stack_to->i_top++;
	stack_to->arr[stack_to->i_top] = stack_from->arr[stack_from->i_top];
	stack_from->arr[stack_from->i_top] = 0;
	stack_from->i_top--;
}

void	r_operation(t_stack *stack)
{
	int		tmp;
	int		i;

	tmp = stack->arr[stack->i_top];
	i = stack->i_top;
	while (i > 0)
		stack->arr[i--] = stack->arr[i - 1];
	stack->arr[0] = tmp;
}

void	r(t_stack *stack_a, t_stack *stack_b, char mode)
{
	t_stack	*stack_main;

	printf("r%c\n", mode);
	if (mode == 'a')
		r_operation(stack_a);
	else if (mode == 'b')
		r_operation(stack_b);
	else if (mode == 'r')
	{
		r_operation(stack_a);
		r_operation(stack_b);
	}
}

void	use(char *command, t_stack *stack_a, t_stack *stack_b)
{
	if (command[0] == 's')
		s(stack_a, stack_b, command[1]);
	else if (command[0] == 'p')
		p(stack_a, stack_b, command[1]);
	else if (command[0] == 'r')
		r(stack_a, stack_b, command[1]);
}

int main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	create_stack_a(&stack_a, argv, argc - 1);
	create_stack_b(&stack_b, argc - 1);
	print_stacks(&stack_a, &stack_b);

	use("ra", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);

	use("pb", &stack_a, &stack_b);
	use("pb", &stack_a, &stack_b);
	use("pb", &stack_a, &stack_b);
	// use("ra", &stack_a, &stack_b);
	// use("rb", &stack_a, &stack_b);
	// use("rr", &stack_a, &stack_b);
	// use("sb", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);

}
