#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return 0;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return 0;
		++i;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_is_prime(atoi(argv[1])));
	return 0;
}