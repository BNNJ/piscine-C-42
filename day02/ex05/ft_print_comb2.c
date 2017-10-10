#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_stuff(int i, int j)
{
	ft_putchar(i / 10 + '0');
	ft_putchar(i % 10 + '0');
	ft_putchar(' ');
	ft_putchar(j / 10 + '0');
	ft_putchar(j % 10 + '0');
	if (i < 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void ft_print_comb2()
{
	int i = 0;
	int j;

	while (i <= 98)
	{
		j = i + 1;
		while(j <= 99)
		{
			ft_print_stuff(i, j);
			++j;
		}
		++i;
	}
}

int main()
{
    ft_print_comb2();
    return 0;
}