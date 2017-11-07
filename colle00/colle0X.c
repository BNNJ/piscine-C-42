#include <unistd.h>

/* ugly init that respects the norm
char	*ft_init(const int n)
{
	if		(n == 0)
		return "-|oooo";
	else if	(n == 1)
		return "**//*\\\\/";
	else if	(n == 2)
		return "BBAACC";
	else if	(n == 3)
		return "BBACAC";
	else if	(n == 4)
		return "BBACCA";
} */

char	*ft_init(const int n)
{
	char *symbols[5] = {"-|oooo", "**/\\\\/", "BBAACC", "BBACAC", "BBACCA"};

	return symbols[n];
}

void	ft_print_line(const char *symb, const int x, const int y, const int j)
{
	int i;
	char c;

	i = 1;
	while (i <= x)
	{
		if (j != 1 && j != y)
			c = (i == 1 || i == x) ? symb[1] : ' ';
		else
		{
			if ((i == 1 || i == x) && j == 1)
				c = (i == 1) ? symb[2] : symb[3];
			else if ((i == 1 || i == x) && j == y)
				c = (i == 1) ? symb[4] : symb[5];
			else
				c = symb[0];
		}
		write(1, &c, 1);
		i++;
	}
}

void	ft_core(int n, const int x, const int y)
{
	char *symb;
	int j;

	j = 1;
	symb = ft_init(n);
	while (j <= y)
	{
		ft_print_line(symb, x, y, j);
		if (j != y)
			write(1, "\n", 1);
		j++;
	}
}