#include <stdlib.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i = 1;

	while (i * i <= nb)
	{
		if (i * i == nb)
			return i; 
		++i;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_sqrt(atoi(argv[1])));
	return 0;
}