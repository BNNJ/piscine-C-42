#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (min - max >= 0 || !(tab = malloc(sizeof *tab * (max - min))))
		return 0;
	while (min < max)
		tab[i++] = min++;
	return tab; 
}

int	main(int argc, char **argv)
{
	int *tab;
	int i;

	if (argc == 3)
		tab = ft_range(atoi(argv[1]), atoi(argv[2]));
	i = 0;
	while (i < atoi(argv[2]) - atoi(argv[1]))
	{
		printf("%d\n", tab[i]);
		++i;
	}
	return 0;
}