#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int	ft_atoi(char *str)
{
	short sign;
	unsigned long long result;

	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	sign = (*str == '-' || *str == '+') ? -(*str++ - 44) : 1;
	while (*str && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return result * sign;
}

int main(int argc, char **argv)
{
	printf("ft_atoi : %i\n", ft_atoi(argv[1]));
	printf("real atoi : %i\n", atoi(argv[1]));
	return 0;
}
