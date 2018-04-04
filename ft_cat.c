#include <unistd.h>
#include <fcntl.h>

void	ft_display(int file_desc)
{
	char buffer;

	buffer = 0;
	while (read(file_desc, &buffer, 1) > 0)
		write(1, &buffer, 1);
	if (read(file_desc, &buffer, 1) < 0)
		write(2, "Error while reading file.\n", 26);
}

void	ft_cat(int argc, char **argv)
{
	int i;
	int file_desc;

	i = 0;
	if (argc < 2)
		ft_display(0);
	else
		while (++i < argc)
		{
			file_desc = open(argv[i], O_RDONLY);
			if (file_desc < 0)
			{
				write(2, "ft_cat: ", 8);
				while (*(argv[i]))
					write(2, (argv[i])++, 1);
				write(2, ": No such file or directory\n", 28);
			}
			else
				ft_display(file_desc);
			close(file_desc);
		}
}

int		main(int argc, char **argv)
{
	ft_cat(argc, argv);
	return 0;
}
