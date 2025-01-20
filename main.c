#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1 || char_error(argv))
		error_exit();
	create_stack_a(&stack_a, argv, argc - 1);
	if (dup_error(&stack_a))
		error_exit();
	create_stack_b(&stack_b, argc - 1);
	print_stacks(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	print_stacks(&stack_a, &stack_b);
	free(stack_a.arr);
	free(stack_b.arr);
}
