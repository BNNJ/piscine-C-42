#include <unistd.h>
void	ft_putnbr(int nb);

void	ft_add(const int a, const int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(const int a, const int b)
{
	ft_putnbr(a - b);
}

void	ft_div(const int a, const int b)
{
	if (b != 0)
		ft_putnbr(a / b);
	else
		write(1, "Stop : division by zero", 23);
}

void	ft_mul(const int a, const int b)
{
	ft_putnbr(a * b);
}

void	ft_mod(const int a, const int b)
{
	if (b != 0)
		ft_putnbr(a % b);
	else
		write(1, "Stop : modulo by zero", 21);
}