#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_stuff(int *tab, int n)
{
	int i = 0;

	while (i <= n - 1)
	{
		ft_putchar(tab[i] + '0');
		++i;
	}
	if (tab[0] != 10 - n)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
}

void ft_print_combn(int n)
{
	int tab[n];
	int i;

	i = -1;
	while (++i <= n - 1)
		tab[i] = i;
	while (tab[0] <= 10 - n)
	{
		i = n - 1;
		while (tab[i] <= 10 - n + i)
		{
			ft_print_stuff(tab, n);
			++tab[i];
		}
		tab[i]--;
		while (tab[i] == 10 - n + i && i != 0)
			--i;
		++tab[i];
		while (i <= n - 1)
			tab[++i] = tab[i - 1] + 1;
	}
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	
	if (argc == 2)
		ft_print_combn(n);
	return 0;
}