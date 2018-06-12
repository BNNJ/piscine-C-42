#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i = -1;

	if (!(*range = malloc(sizeof(int) * (max - min))))
		return 0;
	while (++i < max - min)
		(*range)[i] = min + i;
	return (max - min);
}

int	main(int argc, char **argv)
{
	int *ptr;
	int min = (argc > 1) ? atoi(argv[1]) : 2;
	int max = (argc > 1) ? atoi(argv[2]) : 9;
	int i = 0;

	ft_ultimate_range(&ptr, min, max);
	while (i < max - min)
		printf("%d\n", ptr[i++]);
	return 0;
}
