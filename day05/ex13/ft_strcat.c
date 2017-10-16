#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_len;

	i = 0;
	dest_len = 0;
	while (dest[dest_len])
		++dest_len;
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		++i;
	}
	dest[dest_len + i] = '\0';
	return dest;
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		printf("%s\n", ft_strcat(argv[1], argv[2]));
	return 0;
}