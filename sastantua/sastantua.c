#include <unistd.h>
#define IS_DOOR x == max_width \
&& i >= max_width / 2 + 2 - ((y - 2) % 2 + (y - 2) / 2) - y + j \
&& i <= max_width / 2 + 0 + ((y - 2) % 2 + (y - 2) / 2) - y + j \
&& j > ((y - 3) % 2 == 0 ? 2 : 3)
//	wat
#define IS_KNOB y - 2 >= 5 && x == max_width \
&& i == max_width / 2 - 1 + ((y - 2) % 2 + (y - 2) / 2) - y + j \
&& j == ((y - 3) % 2 == 0 ? 2 : 3) + (y - 2) % 2 + (y - 2) / 2
//	wat²
#define OFFSET ((max_width - x) / 2 + (y - j))
//	width of the last floor - width of current floor / 2
//	+  difference between floor height and current line

void	print_floor(const int x, const int y, const int max_width)
{
	int i;
	int j;

	j = 0;
	while (++j <= y)
	{
		i = -OFFSET;
		while (++i <= 0)
			write(1, " ", 1);
		write(1, "/", 1);
		while (++i <= x - 1 - 2 * (y - j))
		{
			if		(IS_KNOB)
				write(1, "$", 1);
			else if (IS_DOOR)
				write(1, "|", 1);
			else
				write(1, "*", 1);
		}
		write(1, "\\\n", 2);
	}
}

int	width(int x)
{
	if (x == 0)
		return 7;
	return width(x - 1) + 2 * (x + 4 + x % 2 + x / 2);
//	previous floor width + 2 * (height + 1 + 1 every even floor)
}

void	sastantua(int size)
{
	int i;
	int max_width;

	i = -1;
	max_width = width(size - 1);
	while (++i <= size - 1)
		print_floor(width(i), 3 + i, max_width);
}
