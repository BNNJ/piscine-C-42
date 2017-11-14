#include <stdlib.h>
#include <stdio.h>

int	ft_square(int a)
{
	return a * a;
}

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *ret_tab;

	i = 0;
	if (!(ret_tab = malloc(sizeof(int) * length)))
		return 0;
	while (i < length)
		ret_tab[i++] = f(*tab++);
	return ret_tab;
}

int	main()
{
	int i = 0;
	int tab[] = {1, 2, 3, 4, 5};

	while (i < 5)
	{
		printf("%d\n", *(ft_map(tab, 5, ft_square) + i));
		++i;
	}
	return 0;
}