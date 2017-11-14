#include "math.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_div(int a, int b)
{
	if (b != 0)
		ft_putnbr(a / b);
	else
		write(1, "Stop : division by zero", 23);
}

void	ft_mult(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_mod(int a, int b)
{
	if (b != 0)
		ft_putnbr(a % b);
	else
		write(1, "Stop : modulo by zero", 21);
}