char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int len;

	len = 0;
	while (src[len])
	{
		dest[len] = src[len]
		++len;
	}
	dest[len] = '\0';
	return dest;
}
