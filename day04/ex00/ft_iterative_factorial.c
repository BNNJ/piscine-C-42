#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int result;
	int i;

	result = 1;
	i = 1;
	if (nb < 0 || nb >= 13)
		return 0;
	while (i <= nb)
		result *= i++;
	return result;
}

int main()
{
	int i = -7;

	while (i <= 16)
	{
		printf("%i : %i\n", i, ft_iterative_factorial(i));
		++i;
	}
	return 0;
}