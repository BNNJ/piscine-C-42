#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return -1;
	return (index == 0 || index == 1) ? 
		index : ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_fibonacci(atoi(argv[1])));
	return 0;
}