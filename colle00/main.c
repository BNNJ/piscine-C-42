void	ft_core(int n, const int x, const int y);
void	ft_putchar(const char c);

void	ft_putstr(const char *str)
{
	while (str)
		ft_putchar(*str++);
}

int	ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while (*str == '\v' || *str == '\t' || *str == '\r' 
		|| *str == '\n' || *str == '\f' || *str == ' ')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return sign * result;
}

int		main(int argc, char **argv)
{
	int n;
	int x;
	int y;

	n = (argc > 1 && ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 4)
		? ft_atoi(argv[1]) : 0;
	x = (argc > 2 && ft_atoi(argv[2]) >= 1) ? ft_atoi(argv[2]) : 6;
	y = (argc > 3 && ft_atoi(argv[3]) >= 1) ? ft_atoi(argv[3]) : 4;
	ft_core(n, x, y);
	return 0;
}