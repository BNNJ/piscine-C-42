#include <stdio.h>
#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		--n;
		++s1;
		++s2;
	}
	return (!n) ? 0 : *(unsigned char*)s1 - *(unsigned char*)s2;
}

int		main(int argc, char **argv)
{
	char *s1 = (argc >= 2) ? argv[1] : "Hello Darkness My Old Friend";
	char *s2 = (argc >= 3) ? argv[2] : "Hello";
	int n = atoi(argv[3]);

	printf("%d\n", ft_strncmp(s1, s2, n));
	return 0;
}