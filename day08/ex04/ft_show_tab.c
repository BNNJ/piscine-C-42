#include "ft_stock_par.h"

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

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_words_tables(char **tab)
{
	while (*tab)
	{
		while (**tab)
			write(1, (*tab)++, 1);
		write(1, "\n", 1);
		++tab;
	}
}

void	ft_show_tab(t_stock_par *par)
{
	while (par->str)
	{
		ft_putstr(par->copy);
		write(1, "\n", 1);
		ft_putnbr(par->size_param);
		write(1, "\n", 1);
		ft_print_words_tables(par->tab);
		++par;
	}
}