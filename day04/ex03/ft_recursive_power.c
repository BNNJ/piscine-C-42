#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return 0;
	return (power == 0) ? 1 : nb * ft_recursive_power(nb, power - 1); 
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
	return 0;
}