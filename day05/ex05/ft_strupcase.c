#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'z' - 'Z';
		i++;
	}
	return str;
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strupcase(argv[1]));
	return 0;
}