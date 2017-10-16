#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

int		is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return 0;
		j = i ;
		while (base[++j])
			if (base[j] == base[i])
				return 0;
		++i;
	}
	if (i < 2)
		return 0;
	return 1;
}

void	ft_compute(int nbr, int base_len, char *base)
{
	unsigned int n;

	n = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n / base_len > 0)
		ft_compute(n / base_len, base_len, base);
	ft_putchar(base[n % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int base_len;

	base_len = 0;
	while (base[base_len])
		++base_len;
	if (is_valid(base))
		ft_compute(nbr, base_len, base);
}

int		main(int argc, char **argv)
{
	int nbr = atoi(argv[1]);
	char *base = (argc == 3) ? argv[2] : "0123456789";
	ft_putnbr_base(nbr, base);
	return 0;
}