void	ft_putchar(const char c);

// different symbols init function in case the norminette doesn't like the other one.
/*char	*ft_init(const int n)
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
	char *symbols[] = {"-|oooo", "**/\\\\/", "BBAACC", "BBACAC", "BBACCA"};

	return symbols[n];
}

void	ft_print_line(const char *symb, const int x, const int y, const int j)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (j != 1 && j != y)
			ft_putchar((i == 1 || i == x) ? symb[1] : ' ');
		else
		{
			if ((i == 1 || i == x) && j == 1)
				ft_putchar((i == 1) ? symb[2] : symb[3]);
			else if ((i == 1 || i == x) && j == y)
				ft_putchar((i == 1) ? symb[4] : symb[5]);
			else
				ft_putchar(symb[0]);
		}
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
			ft_putchar('\n');
		j++;
	}
}
