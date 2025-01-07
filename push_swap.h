
#include <stdlib.h>
#include <unistd.h>

// ↓ will replace these
#include <stdio.h>
#include <string.h>
// ↑

typedef struct	s_stack
{
	ssize_t	i_top;
	ssize_t	i_max;
	int		*arr;		
}				t_stack;

void    print_stacks(t_stack *stack_a, t_stack *stack_b);
void	create_stack_a(t_stack *stack_a, char *argv[], ssize_t size);
void	create_stack_b(t_stack *stack_b, ssize_t size);
void	use(char *command, t_stack *stack_a, t_stack *stack_b);

void	p_operation(t_stack *stack_to, t_stack *stack_from);
void	p(t_stack *stack_a, t_stack *stack_b, char mode);

void	r_operation(t_stack *stack);
void	r(t_stack *stack_a, t_stack *stack_b, char mode);

void	rr_operation(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b, char mode);

void    s_operation(t_stack *stack);
void	s(t_stack *stack_a, t_stack *stack_b, char mode);
