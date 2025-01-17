
#include <stdlib.h>
#include <unistd.h>

// ↓ will replace these
// #include <stdio.h>
// #include <string.h>
// ↑

typedef struct	s_stack
{
	ssize_t	i_top;
	ssize_t	i_max;
	int		*arr;
	int		greatest;
}				t_stack;

void    print_stacks(t_stack *stack_a, t_stack *stack_b);
void	create_stack_a(t_stack *stack_a, char *argv[], ssize_t size);
void	create_stack_b(t_stack *stack_b, ssize_t size);
void	use(char *command, t_stack *stack_a, t_stack *stack_b);

void	p_operation(t_stack *stack_to, t_stack *stack_from);
int		p(t_stack *stack_a, t_stack *stack_b, char mode);

void	r_operation(t_stack *stack);
int		r(t_stack *stack_a, t_stack *stack_b, char mode);

void	rr_operation(t_stack *stack);
int		rr(t_stack *stack_a, t_stack *stack_b, char mode);

void    s_operation(t_stack *stack);
int		s(t_stack *stack_a, t_stack *stack_b, char mode);

int		valid(t_stack *stack_b, ssize_t i, int num);
void	rotate_b(t_stack *stack_a, t_stack *stack_b);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack, ssize_t i_start, ssize_t i_end, char mode);
void	rotate_to(t_stack *stack_a, t_stack *stack_b, char *mode, ssize_t i_dest);
void	a_self_correct(t_stack *stack_a, t_stack *stack_b);

int		ft_atoi(const char *str);
char 	*ft_strcpy(char *d, const char *s);
char 	*ft_strcat(char *a, char *b);
void	ft_putmsg_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
