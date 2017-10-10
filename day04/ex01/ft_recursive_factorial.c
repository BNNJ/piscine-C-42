#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return 1;
	return (nb < 0 || nb >= 13) ? 0 : (nb * ft_recursive_factorial(nb - 1));
}

int main()
{
	int i = -7;

	while (i <= 16)
	{
		printf("%i : %i\n", i, ft_recursive_factorial(i));
		i++;
	}
	return 0;
}