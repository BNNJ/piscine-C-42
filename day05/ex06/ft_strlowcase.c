#include <stdio.h>

char	*ft_lowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'z' - 'Z';
		i++;
	}
	return str;
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_lowcase(argv[1]));
	return 0;
}