#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int *tab;
	int i = 0;

	len = max - min;
	if (len <= 0 || !(tab = malloc(sizeof(int) * len)))
	{
		range = 0;
		return 0;
	}
	while (min < max)
		tab[i++] = min++;
	*range = tab;
	return len;
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