#include <unistd.h>

int	ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	sign = (*str == '-' || *str == '+') ? -(*str++ - 44) : 1;
	while (*str && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return sign * result;
}

void	ft_putnbr(int nb)
{
	unsigned int nbr = nb;
	const char base[10] = "0123456789";

	if (nb < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	write(1, base + nbr % 10, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return *s1 - *s2 == 0;
}
