#include <stdio.h>

int	ft_strcmp(char *s1)
{
	char *s2 = "Hello";

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return 0;
		++s1;
		++s2;
	}
	return 1;
}

int	ft_any(char **tab, int(*f)(char*))
{
	while (*tab)
		if (f(*tab++))
			return 1;
	return 0;
}

int	main()
{
	char *tab[] = {"Helli", "Darknesssssss", "My", "Old", "Friend", 0};

	printf("%d\n", ft_any(tab, ft_strcmp));
	return 0;
}
