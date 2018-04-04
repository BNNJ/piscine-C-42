#include <unistd.h>
#include <fcntl.h>

int		ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	sign = (*str == '-' || *str == '+') ? -(*str++ - 44) : 1;
	while (*str && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return sign * result;
}

int		ft_file_size(char *file_name)
{
	int		size;
	char	buffer;
	int		file_desc;

	file_desc = open(file_name, O_RDONLY);
	size = 0;
	if (file_desc < 0)
	{
		write(2, "ft_tail: ", 9);
		while (*file_name)
			write(2, file_name++, 1);
		write(2, ": No such file or directory\n", 28);
		return -1;
	}
	else
		while (read(file_desc, &buffer, 1) > 0)
			++size;
	close(file_desc);
	return size;
}

void	ft_display(char *file_name, int size, int offset)
{
	char	buffer;
	int		file_desc;
	int		n;

	n = 0;
	file_desc = open(file_name, O_RDONLY);
	while (read(file_desc, &buffer, 1) > 0)
	{
		if (++n >= size - offset + 1)
			write(1, &buffer, 1);
	}
	close(file_desc);
}

void	ft_print_header(int i, int arg_offset, char *file_name)
{
	if (i >= 4 + arg_offset)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	while (*file_name)
		write(1, file_name++, 1);
	write(1, " <==\n", 5);
}

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	int		offset;
	int		arg_offset;

	i = 0;
	offset = 10;
	arg_offset = 0;
	if (*(argv[1]) == '-' && *(argv[1] + 1) == 'c')
	{
		i = (*(argv[1] + 2) == '\0') ? 2 : 1;
		offset = (*(argv[1] + 2) == '\0') 
			? ft_atoi(argv[2]) : ft_atoi(argv[1] + 2);
		arg_offset = i;
	}
	while (++i < argc)
	{
		if (argc >= 3 + arg_offset)
			ft_print_header(i, arg_offset, argv[i]);
		size = ft_file_size(argv[i]);
		ft_display(argv[i], size, offset);
	}
	return 0;
}
