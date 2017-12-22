#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int puissance(int nb, int i)
{
	if (i == 0)
	nb = 1;
	while(i>1)
	  	return nb *= puissance(nb, i - 1);
	return nb;
}

void ft_putnbr_base(int nbr, char *base)
{
	unsigned int n = 0, i = 0, j = 1, q = 0, temp = 0, nb;

	while (base[n])
		++n;
	if(q == 0)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' 
			|| n == 0 || n == 1)
		{
			ft_putchar('\0');
			q = 1;
		}
		while (i <= n - 2)
		{
			while (j <= n - 1)
			{
				if (base[i] == base[j] || base[j] == '+' 
					|| base[j] == '-' || base[j] == ' ')
				{
					ft_putchar('\0');
					q = 1;
				}
				else
					++j;
			}
			i++;
			j = i + 1;
		}
	}
	i = 0;
	if (q == 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = -nbr;
		}
		else
			nb = nbr;
		temp = nb;
		while (temp / n != 0)
		{
			temp /= n;
			i++;
		}
		temp = nb;
		while (i + 1 >= 1)
		{
			j = temp / puissance(n,i);
			ft_putchar(base[j]);
			temp = temp % (puissance(n, i));
			i--;
		}
	}
	ft_putchar('\n');
}
		
int		main(int argc, char **argv)
{
	int nbr = atoi(argv[1]);
	char *base = (argc == 3) ? argv[2] : "0123456789";
	ft_putnbr_base(nbr, base);
	return 0;
}