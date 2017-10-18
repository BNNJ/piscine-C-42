#include <unistd.h>

void ft_putnbr(int nb)
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
