#include <unistd.h>
#include <stdio.h>

void	print_floor(const int x, const int y, int const max_width)
{
	int i;
	int j;

	j = 0;
	while (++j <= y)
	{
		i = -(max_width / 2 - x / 2 + (y - j));
		while (++i <= 0)
			write(1, " ", 1);
		write(1, "/", 1);
		while (++i <= x - 1 - 2 * (y - j))
		{
			if (y - 2 >= 5 && x == max_width
				&& i == max_width / 2 - 1 + ((y - 2) % 2 + (y - 2) / 2) - y + j
				&& j == ((y - 3) % 2 == 0 ? 2 : 3) + (y - 2) % 2 + (y - 2) / 2)
				write(1, "$", 1);
			else if (x == max_width 
				&& i >= max_width / 2 + 2 - ((y - 2) % 2 + (y - 2) / 2) - y + j
				&& i <= max_width / 2 + 0 + ((y - 2) % 2 + (y - 2) / 2) - y + j
				&& j > ((y - 3) % 2 == 0 ? 2 : 3))
				write(1, "|", 1);
			else
				write(1, "*", 1);
		}
		write(1, "\\\n", 2);
	}
}

int		compute_width(int x)
{
	if (x == 0)
		return 7;
	return compute_width(x - 1) + 2 * (x + x % 2 + x / 2 + 4);
}

void	sastantua(int size)
{
	int width;
	int height;
	int i;
	int max_width;

	i = 0;
	max_width = compute_width(size - 1);
	while (i <= size - 1)
	{
		height = 3 + i;
		width = compute_width(i);
		print_floor(width, height, max_width);
		i++;
	}
}