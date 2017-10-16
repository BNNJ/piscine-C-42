#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
	}
	return 0;
}