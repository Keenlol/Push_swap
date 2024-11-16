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

int main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	create_stack_a(&stack_a, argv, argc - 1);
	create_stack_b(&stack_b, argc - 1);
	print_stacks(&stack_a, &stack_b);
}
