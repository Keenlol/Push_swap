#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stack
{
	size_t	i_top;
	size_t	i_max;
	int		*arr;		
}				t_stack;



void    print_stacks(int *a, int *b)
{
	size_t  i;
	
	i = 0;
	printf("-----------------\n");
	while(a[i])
	{
		printf("%d %d\n", a[i], b[i]);
		i++;
	}
	printf("_ _\na b\n-----------------\n");
}

t_stack*	create_stack(size_t size, int *arr)
{
	t_stack	new_stack;
	size_t	i;

	new_stack.i_max = size;
	if (*arr == NULL)
		new_stack.i_top = size;
	else
		new_stack.i_top = -1;
}

int main(int argc, char *argv[])
{
	int *a;
	int *b;
	
	b = (int *)malloc((argc - 1) * sizeof(t_stack));
	if (!b)
		return (0);
	a = (int *)malloc((argc - 1) * sizeof(t_stack));
	if (!a)
		return (0);

	read_into(argv, a);

	print_stacks(a, b);
	
}
