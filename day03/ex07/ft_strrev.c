char *ft_strrev(char *str)
{
	char a;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
		++i;
	while (i-- > j)
	{
		a = str[i];
		str[i] = str[j];
		str[j++] = a;
	}
	return str;
}
