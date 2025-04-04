#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	ssize_t	i_top;
	ssize_t	i_max;
	int		*arr;
	int		greatest;
}				t_stack;

typedef struct s_cost
{
	ssize_t	current;
	ssize_t	lowest;
}				t_cost;

void	error_exit(void);
int		arg_is_num(char *str);
int		char_error(char *argv[]);
int		dup_error(t_stack *stack);

int		ft_atoi(const char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
void	ft_putmsg_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		main(int argc, char *argv[]);

void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	a_self_correct(t_stack *stack_a, t_stack *stack_b);
void	b_self_correct(t_stack *stack_a, t_stack *stack_b);
void	push_back(t_stack *stack_a, t_stack *stack_b);
int		a_is_sorted(t_stack *stack_a);

void	p_operation(t_stack *stack_to, t_stack *stack_from);
int		p(t_stack *stack_a, t_stack *stack_b, char mode);

void	r_operation(t_stack *stack);
int		r(t_stack *stack_a, t_stack *stack_b, char mode);

void	rr_operation(t_stack *stack);
int		rr(t_stack *stack_a, t_stack *stack_b, char mode);

void	s_operation(t_stack *stack);
int		s(t_stack *stack_a, t_stack *stack_b, char mode);

void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	create_stack_a(t_stack *stack_a, char *argv[], ssize_t size);
void	create_stack_b(t_stack *stack_b, ssize_t size);
void	use(char *command, t_stack *stack_a, t_stack *stack_b);
void	find_good_spot_b(ssize_t *i_b, t_stack *stack_b, int num);

int		valid(t_stack *stack_b, ssize_t i, int num);
void	rotate_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_to(t_stack *stack_a, t_stack *stack_b, char *m, ssize_t i_dst);
ssize_t	cal_cost(ssize_t i_atop, ssize_t i_a, ssize_t i_btop, ssize_t i_b);
void	magic(t_stack *stack_a, t_stack *stack_b, ssize_t *i_a, ssize_t *i_b);

#endif
