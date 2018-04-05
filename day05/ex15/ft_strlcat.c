#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len + 1 < size)
	{
		i = 0;
		while (i < size - 1 - dst_len && src[i])
		{
			dst[dst_len + i] = src[i];
			++i;
		}
		dst[dst_len + i] = '\0';
	}
	return (dst_len > size ? src_len + size : src_len + dst_len);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
		printf("%s, %d, %s\n", 
			argv[1], ft_strlcat(argv[1], argv[2], atoi(argv[3])), argv[1]);
	return 0;
}
