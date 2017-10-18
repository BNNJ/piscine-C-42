#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_to_base(int n, char *base)
{
	char *result;
	int num_len;
	int base_len;
	int temp;

	temp = n;
	base_len = 0;
	while (base[base_len])
		++base_len;
	num_len = 1;
	while (temp >= base_len)
	{
		++num_len;
		temp /= base_len;
	}
	if (!(result = malloc(num_len + 1)))
		return "error : malloc failed";
	result[num_len] = '\0';
	while (--num_len >= 0)
	{
		result[num_len] = base[n % base_len];
		n /= base_len;
	}
	return result;
}

int		ft_search_base(char c, char *base)
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

int		ft_atoi_base(char *str, char *base)
{
	short sign;
	unsigned int result;
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return (is_valid(nbr, base_from))
		? ft_to_base(ft_atoi_base(nbr, base_from), base_to)
		: "error : invalid base";
}

int		main(int argc, char **argv)
{
	char *n = (argc > 1) ? argv[1] : "424242";
	char *base_from = (argc > 2) ? argv[2] : "0123456789abcdef";
	char *base_to = (argc > 3) ? argv[3] : "01";

	printf("%s\n", ft_convert_base(n, base_from, base_to));
	return 0;
}