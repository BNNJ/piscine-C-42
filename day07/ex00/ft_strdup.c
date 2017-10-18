#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char *new_str;
	int i;

	i = 0;
	while (src[i])
		++i;
	if (!(new_str = malloc(i + 1)))
		return NULL;
	while (*src)
		*new_str++ = *src++;
	*new_str = '\0';
	return new_str - i;
}

int		main()
{
	char *str = "Hello Darkness My Old Friend";
	printf("%s\n", ft_strdup(str));
	return 0;
}