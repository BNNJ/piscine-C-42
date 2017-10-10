#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_sort_integer_table(int *tab, int size)
{
	int i = 1;
	int temp;

	while (i <= size - 1)
	{
		if (tab[i] < tab[i - 1])
		{
			temp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = temp;
			i = 0;
		}
		++i;
	}
}

int main()
{
	int i = 0;
	int tab[] = {4, 3, 5, 6, 9, 1, 2, 8, 7};

	ft_sort_integer_table(tab, 9);
	while (i <= 8)
		ft_putchar(tab[i++] + '0');
	return 0;
}