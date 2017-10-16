int		ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!(*str <= 'z' && *str >= 'a'))
			return 0;
		++str;
	}
	return 1;
}