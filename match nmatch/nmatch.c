#include <stdio.h>

int nmatch(char *s1, char *s2)
{
	if (*s1 == *s2)
		return *s1 ? nmatch(s1 + 1, s2 + 1) : 1;
	if (!*s1)
		return *s2 == '*' ? nmatch(s1, s2 + 1) : 0;
	return *s2 == '*' ? nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2) : 0;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d\n", nmatch(argv[1], argv[2]));
	return 0;
}
