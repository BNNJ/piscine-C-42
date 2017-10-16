#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int src_len;

	src_len = 0;
	while (src[src_len])
		++src_len;
	while (*src && --size)
		*dest++ = *src++;
	if (!size)
		*dest = '\0';
	return src_len;
}

int		main(int argc, char **argv)
{
	char dest[255];
	char dest2[255];

	if (argc == 3)
	{
		printf("%d, %s\n", ft_strlcpy(dest, argv[1], atoi(argv[2])), dest);
		printf("%d, %s\n", strlcpy(dest2, argv[1], atoi(argv[2])), dest2);
	}
	return 0;
}