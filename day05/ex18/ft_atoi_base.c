#include <stdio.h>

int	ft_search_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return i;
		++i;
	}
	return -1;
}

int	is_valid(char *str, char *base)
{
	int i;
	int j;

	while (*str)
		if (ft_search_base(*str++, base) == -1)
			return 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return 0;
		j = i;
		while (base[++j])
			if (base[j] == base[i])
				return 0;
		++i;
	}
	if (i < 2)
		return 0;
	return 1;
}

int	ft_compute(char *str, char *base)
{
	short sign;
	unsigned long long result;
	unsigned int base_len;

	base_len = 0;
	while (base[base_len])
		++base_len;
	result = 0;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str)
	{
		result = result * base_len + (ft_search_base(*str, base));
		++str;
	}
	return sign * result;
}

int	ft_atoi_base(char *str, char *base)
{
	if (is_valid(str, base))
		return ft_compute(str, base);
	else 
		return 0;
}

int	main(int argc, char **argv)
{
	char *str = argv[1];
	char *base = (argc == 3) ? argv[2] : "0123456789ABCDEF";
	printf("%d\n", ft_atoi_base(str, base));
	return 0;
}