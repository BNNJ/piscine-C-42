#include <stdio.h>

int	ft_compare(int x, int y)
{
	return x - y;
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return 0;
		++i;
	}
	return 1;
}

int main()
{
//	int tab[] = {4, 3, 5, 8, 1, 7, 2, 6, 9};
	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("%d\n", ft_is_sort(tab, 0, ft_compare));
	return 0;
}