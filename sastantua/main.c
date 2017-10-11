#include <unistd.h>
void	sastantua(int size);

int		ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
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
		(ft_atoi(argv[1]) > 0) ? sastantua(ft_atoi(argv[1])) : 
		write(1, "invalid size, please enter a positive number", 44);
	else 
		sastantua(5);
	return 0;
}
