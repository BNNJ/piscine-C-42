#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return *s1 - *s2;
}

int		main(int argc, char **argv)
{
	char *s1 = (argc >= 2) ? argv[1] : "Hello Darkness My Old Friend";
	char *s2 = (argc >= 3) ? argv[2] : "Hello";

	printf("%d\n", ft_strcmp(s1, s2));
	return 0;
}