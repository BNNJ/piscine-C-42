#include <unistd.h>
#include <stdlib.h>

void ft_putnbr(int nb)
{
	unsigned int nbr = nb;
	const char base[10] = "0123456789";
	
	if (nb < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	write(1, base + nbr % 10, 1);
}

int main(int argc, char **argv)
{
	ft_putnbr(atoi(argv[1]));
	return 0;
}
