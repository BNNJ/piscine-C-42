#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int src_len;

	dest_len = 0;
	src_len = 0;
	while (*dest++ && size--)
		++dest_len;
	while (*src)
	{
		if (--size)
			*dest = *src;
		++src_len;
		++dest;
		++src;
	}
	if (!size && !*src)
		*dest = '\0';
	return dest_len + src_len;
}

int		main(int argc, char **argv)
{
	if (argc == 4)
		printf("%s, %d, %s\n", 
			argv[1], ft_strlcat(argv[1], argv[2], atoi(argv[3])), argv[1]);
	return 0;
}