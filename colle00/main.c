void	ft_core(int n, const int x, const int y);

int	ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		++str;
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
	x = (argc > 2 && ft_atoi(argv[2]) >= 1) ? ft_atoi(argv[2]) : 18;
	y = (argc > 3 && ft_atoi(argv[3]) >= 1) ? ft_atoi(argv[3]) : 12;
	ft_core(n, x, y);
	return 0;
}