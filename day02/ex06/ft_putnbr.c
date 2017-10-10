#include <unistd.h>
#include <stdlib.h>

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

int main(int argc, char **argv)
{
	ft_putnbr(atoi(argv[1]));
	return 0;
}