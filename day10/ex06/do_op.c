#include "math.h"

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

void	ft_putnbr(const int nb)
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

int 	main(int argc, char **argv)
{
	void (*tab[11])(int, int);
	void (*op)(int, int);

	tab[0] = &ft_mod;
	tab[5] = &ft_mult;
	tab[6] = &ft_add;
	tab[8] = &ft_sub;
	tab[10] = &ft_div;

	if (argc != 4)
		return 0;
	else if (CHECK_ARG(*argv[2]))
	{
		op = tab[(*argv[2]) - 37];
		op(ft_atoi(argv[1]), ft_atoi(argv[3]));
	}
	else
		write(1, "0", 1);
	return 0;
}
