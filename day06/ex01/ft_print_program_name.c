#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc == 1)
		while (*argv[0])
			write(1, argv[0]++, 1);
	return 0;
}