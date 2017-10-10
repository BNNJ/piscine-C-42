#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	unsigned int nbr = nb;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void ft_print_stuff(int k, int i, int n)
{
	ft_putnbr(k);
	if (i != n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int	ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while (*str == '\v' || *str == '\t' || *str == '\r' 
		|| *str == '\n' || *str == '\f' || *str == ' ')
		++str;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return sign * result;
}

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return 0;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return 0;
		++i;
	}
	return 1;
}

void nfirstprime(int n)
{
	int i = 1;
	int k = 2;
	int a = 0;

	while (i <= n)
	{
		if (ft_is_prime(k))
		{
			ft_print_stuff(k, i, n);
			i++;
		}
		k += (k < 7) ? 1 : (a += 2) % 4 + 2;
//		$
	}
}

int main(int argc, char **argv)
{
	nfirstprime(ft_atoi(argv[1]));
	return 0;
}