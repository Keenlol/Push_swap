#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	negative_holder;

	num = 0;
	negative_holder = 1;
	while ((9 <= *str && *str <= 13)
		|| *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative_holder *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += (*str - '0');
		str++;
	}
	num *= negative_holder;
	return (num);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_end;

	dest_end = dest;
	while (*dest_end)
		dest_end++;
	while (*src)
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}
	*dest_end = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*saved;

	saved = dest;
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (saved);
}

void	ft_putmsg_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	nbr_char;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr < 10)
	{
		nbr_char = nbr + '0';
		write(fd, &nbr_char, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
	}
	ft_putnbr_fd(nbr % 10, fd);
}
