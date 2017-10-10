#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void ft_ft(int *nbr)
{
	*nbr = 42;
}

int main(void)
{
	int i;
	int *nbr;

	nbr = &i;
	ft_ft(nbr);
	ft_putnbr(i);
	return 0;
}