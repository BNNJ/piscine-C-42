#include <stdio.h>

int puissance(int nb, int p)
{
	if (p == 0)
	nb = 1;
	while (p >= 1)
		return nb *= puissance(nb, p - 1);
	return nb;
}

int caracteres(char *str, int i)
{
	while (str[i])
		i++;
	return i;
}

int test_base(char *base)
{
	int i = 0, j = 1, k = 1, n = caracteres(base, 0);
	if (n == 0 || n == 1 || base[i] == '+' || base[i] == '-'
		|| (base[i] >= 0 && base[i] <= 32))
		k = 0;
	if (k == 1)
	{
		while (i < n - 1 && k == 1)
		{
			while (j < n && k == 1)
			{
				if (base[j] == '+' || base[j] == '-' || base[i] == base[j]
					|| (base[j] <= 32 && base[j] >= 0))
					k = 0;
				++j;
			}
			++i;
			j = i + 1;
		}
	}
	return k;
}

int ft_atoi_base(char *str, char *base)
{
	int nbr = 0, k = test_base(base), r, i = 0, j = 0;
	int s = caracteres(str, 0), b = caracteres(base, 0);

	if (k == 1)
	{
		while (str[i] == '+' || str[i] == '-' || (str[i] >= 0 && str[i] <= 32))
			i++;
		r = i;
		while (i < s && k == 1)
		{
			if (j < b && k == 1)
			{
				if (str[i] == base[j] && k == 1)
				{
					nbr += puissance(b, s - i - 1) * j;
					++i;
					j = 0;
				}
				else
					++j;
			}
			else
			{
				nbr = 0;
				k = 0;
			}
		}
		if (str[r - 1] == '-')
			nbr = -nbr;
	}
	return nbr;
}

int	main(int argc, char **argv)
{
	char *str = (argc >= 2) ? argv[1] : "101010";
	char *base = (argc == 3) ? argv[2] : "0123456789ABCDEF";
	printf("%d\n", ft_atoi_base(str, base));
	return 0;
}