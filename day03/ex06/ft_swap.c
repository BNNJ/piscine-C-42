#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b; 
	*b = c;
}

int main(int ac, char **av)
{
	int a = atoi(av[1]);
	int b = atoi(av[2]);
	int *ptra = &a;
	int *ptrb = &b;

	ft_putchar(a + '0');
	ft_putchar(' ');
	ft_putchar(b + '0');
	ft_putchar(',');
	ft_swap(ptra, ptrb);
	ft_putchar(a + '0');
	ft_putchar(' ');
	ft_putchar(b + '0');
	return 0;	
}