void	ft_putchar(const char c);

char	*ft_init(const int n)
{
	if		(n == 0)
		return "-|oooo";
	else if	(n == 1)
		return "**/\\\\/";
	else if	(n == 2)
		return "BBAACC";
	else if	(n == 3)
		return "BBACAC";
	else if	(n == 4)
		return "BBACCA";
}

void	ft_core(int n, const int x, const int y)
{
	char *symbols;
	int i;
	int j;

	j = 1;
	symbols = ft_init(n);
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			if (j == 1)
			{
				if (i == 1 || i == x)
					ft_putchar((i == 1) ? symbols[2] : symbols[3]);
				else
					ft_putchar(symbols[0]);
			}
			else if (j == y)
			{
				if (i == 1 || i == x)
					ft_putchar((i == 1) ? symbols[4] : symbols[5]);
				else
					ft_putchar(symbols[0]);
			}
			else 
			{
				if (i == 1 || i == x)
					ft_putchar(symbols[1]);
				else 
					ft_putchar(' ');
			}
			i++;
		}	
		if (j != y)
			ft_putchar('\n');
		j++;
	}
}