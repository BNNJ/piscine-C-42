#include <unistd.h>
#include <stdio.h>

int	nb_lines(int size)
{
	return (size + 2) * (size + 3) / 2 - 3;
}

int	nb_stars(int line, int floor, int stars, int i, int k)
{
	if (i < line && i < nb_lines(floor))
		return nb_stars(line, floor,  stars + 2, i + 1, k);
	if (i == nb_lines(floor) && i < line && floor % 2 == 0)
		return nb_stars(line,floor + 1, stars + k, i + 1, k + 2);
	if (i == nb_lines(floor) && i < line && floor % 2 == 1)
		return nb_stars(line, floor + 1, stars + k, i + 1, k);
	return stars;
}

void	print_spaces(int size, int line, int floor, int spaces, int k)
{
	int	i;
	i = 1;

	if (line < nb_lines(size) && line > nb_lines(floor) && floor % 2 == 0)
		print_spaces(size, line,floor + 1, spaces, k + 1);
	if (line < nb_lines(size) && line > nb_lines(floor) && floor % 2 == 1)
		print_spaces(size, line, floor+1, spaces, k);
	else if (line < nb_lines(size) && line < nb_lines(floor))
		print_spaces(size, line + 1, floor, spaces + 1, k);
	else if (line < nb_lines(size) && line == nb_lines(floor) && floor % 2 == 0)
		print_spaces(size, line + 1, floor + 1, spaces + k, k + 1);
	else if (line < nb_lines(size) && line == nb_lines(floor) && floor % 2 == 1)
		print_spaces(size, line + 1, floor + 1, spaces + k, k);
	else
	{
		while (i <= spaces)
		{
			write(1, " ", 1);
			i++;
		}
	}
}

void	print_line(int line, int size, int size_door)
{
	int	i;
	i = 1;	
	print_spaces(size, line, 1, 0, 3);
	write(1, "/", 1);	
	while (i <= nb_stars(line, 1, 1, 1,6))
	{
		if (line > nb_lines(size) - size_door
			&& i > (nb_stars(line, 1, 1, 1, 6) - size_door) / 2
			&& i <= (nb_stars(line, 1, 1, 1, 6) + size_door) / 2)
		{
			if (line == nb_lines(size) - (size_door - 1) / 2
				&& i == (nb_stars(line, 1, 1, 1, 6) + size_door) / 2 - 1
				&& size_door >= 5)
				write(1, "$", 1);
			else
				write(1, "|",1);
		}
		else
		{
			write(1, "*", 1);
		}
		++i;
	}
	write(1, "\\", 1);
	write(1, "\n", 1);
}

void	sastantua(int size)
{
	int	line, size_door, i;
	
	line = 1;
	i = 1;
	size_door = 1;
	while (2 * i < size)
	{
		size_door+=2;
		i++;
	}
	while (line <= nb_lines(size))
	{
		print_line(line, size, size_door);
		line++;
	}	
}

/******************************************************************************/

int		ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while (*str == '\v' || *str == '\t' || *str == '\r' 
		|| *str == '\n' || *str == '\f' || *str == ' ')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return sign * result;
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		(ft_atoi(argv[1]) > 0)
			? sastantua(ft_atoi(argv[1]))
			: write(1, "invalid size, please enter a positive number", 44);
	else 
		sastantua(5);
	return 0;
}