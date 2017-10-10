#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (power < 0)
		return 0;
	while (i <= power)
	{
		result = result * nb;
		++i;
	}
	return result;
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
	printf("%d, %s\n", argc, argv[0]);
	return 0;
}