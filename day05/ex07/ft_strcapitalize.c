#include <stdio.h>

int		is_alphanum(const char c)
{
	if ((c <= 'z' && c >= 'a') 
		|| (c <= 'Z' && c >= 'A') 
		|| (c <= '9' && c >= '0'))
		return 1;
	else
		return 0;
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && !is_alphanum(str[i - 1]))
			str[i] -= 'z' - 'Z';
		else if (str[i] >= 'A' && str[i] <= 'Z' && is_alphanum(str[i - 1]))
			str[i] += 'z' - 'Z';
		++i;
	}
	return str;
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strcapitalize(argv[1]));
	return 0;
}