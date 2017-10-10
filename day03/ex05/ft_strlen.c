#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return i;
}

int main(int ac, char **av)
{
	ft_putnbr(ft_strlen(av[1]));
	return 0;
}