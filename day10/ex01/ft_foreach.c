#include <unistd.h>

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

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}

int	main()
{
	int tab[] = {1, 2, 3, 4, 5};

	ft_foreach(tab, 5, ft_putnbr);
	return 0;
}
