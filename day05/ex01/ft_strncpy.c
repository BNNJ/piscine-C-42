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
