#include <unistd.h>

int	match(char *s1, char *s2)
{
	if (*s2 == '*')
		return match(s1, s2 + 1);
	if (!*s2 || !*s1)
		return (*s2 == *s1) || (!*s2 && *(s2 - 1) == '*');
	return (match(s1 + 1, s2 + 1) && *s2 == *s1)
		|| (match(s1 + 1, s2) && *(s2 - 1) == '*');
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (match(argv[1], argv[2]))
			write(1, "match !\n", 8);
		else
			write(1, "no match :(\n", 12);
	} 
	return 0;
}
