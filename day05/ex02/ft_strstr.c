#include <stdio.h>
/*
int		ft_check(char *str, char *to_find)
{
	if (!*to_find)
		return 1;
	return (*to_find == *str) ? ft_check(str + 1, to_find + 1) : 0;
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return str;
	while (*str && *to_find)
	{
		if (ft_check(str, to_find))
			return str;
		str++;
	}
	return NULL;
}
*/
char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return str;
	if (!*str)
		return NULL;
	return (*to_find == *str && ft_strstr(str + 1, to_find + 1) == str + 1)
		? str : ft_strstr(str + 1, to_find); 
}

