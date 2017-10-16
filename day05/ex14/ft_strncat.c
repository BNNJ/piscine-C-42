#include <stdio.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int dest_len;

	i = 0;
	dest_len = 0;
	while (dest[dest_len])
		++dest_len;
	while (src[i] && i < nb)
	{
		dest[dest_len + i] = src[i];
		++i;
	}
	dest[dest_len + i] = '\0';
	return dest;
}

int		main(int argc, char **argv)
{
	if (argc == 4)
		printf("%s\n", ft_strncat(argv[1], argv[2], atoi(argv[3])));
	return 0;
}