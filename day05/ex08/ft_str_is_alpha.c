int		ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!((*str <= 'z' && *str >= 'a') || (*str <= 'Z' && *str >= 'A')))
			return 0;
		++str;
	}
	return 1;
}