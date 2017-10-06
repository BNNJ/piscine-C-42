void	sastantua(int size);

int		ft_atoi(char *str)
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
	if (argc == 2)
		sastantua(ft_atoi(argv[1]));
	return 0;
}