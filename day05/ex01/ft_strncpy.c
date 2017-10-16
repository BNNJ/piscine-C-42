#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, const unsigned int n)
{
	unsigned int i;
	unsigned int src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		++src_len;
	while (i <= n - 1 && src[i])
	{
		dest[i] = (i <= src_len) ? src[i] : '\0';
		++i;
	}
	return dest;
}

int		main(int argc, char **argv)
{
	char dest[255];

	if (argc > 2)
		ft_strncpy(dest, argv[1], atoi(argv[2]));
	printf("%s\n", dest);
	return 0;
}