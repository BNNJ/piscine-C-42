#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void colle(int a, int b)
{
	int i = 0; 
	int j = 0;

	while (i < b)
	{
		while (j < a)
		{
			if (i == 0 || i == b - 1)
				if (j == 0 || j == a - 1)
				{
					ft_putchar('o');
						if (j == a - 1)
							ft_putchar('\n');
				}
				else
					ft_putchar('-');
			else
				if (j == 0 || j == a - 1)
				{
					ft_putchar('|');
						if(j == a - 1)
							ft_putchar('\n');
				}
				else
					ft_putchar(' ');
			j++;
		}
		i++;
		j = 0;
	}
}

int main()
{
	colle(4, -1);
	return 0;
}