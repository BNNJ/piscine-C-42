#include <stdio.h>

int	ft_strcmp(char *s1)
{
	char *s2 = "Hello";

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return 0;
		++s1;
		++s2;
	}
	return 1;
}

int	ft_count_if(char **tab, int(*f)(char*))
{
	int count;

	count = 0;
	while (*tab)
		if (f(*tab++))
			++count;
	return count;
}

int main()
{
	char *tab[] = {"Hello", "Darknesssssss", "Hello", "My", "Old", "Hello", 0};

	printf("%d\n", ft_count_if(tab, ft_strcmp));
	return 0;
}