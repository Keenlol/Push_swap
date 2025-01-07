#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	create_stack_a(&stack_a, argv, argc - 1);
	create_stack_b(&stack_b, argc - 1);

	print_stacks(&stack_a, &stack_b);

	use("sa", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);
	
	use("pb", &stack_a, &stack_b);
	use("pb", &stack_a, &stack_b);
	use("pb", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);

	use("rr", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);

	use("rrr", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);

	use("sa", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);

	use("pa", &stack_a, &stack_b);
	use("pa", &stack_a, &stack_b);
	use("pa", &stack_a, &stack_b);

	print_stacks(&stack_a, &stack_b);
}
