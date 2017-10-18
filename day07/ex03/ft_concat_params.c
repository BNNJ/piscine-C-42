#include <stdlib.h>
#include <stdio.h>

char	*ft_concat_params(int argc, char **argv)
{
	char *str;
	unsigned int len;
	int i;
	unsigned int j;

	i = 0;
	len = argc - 1;
	while (++i <= argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			++len;
			++j;
		}
	}
	if (!(str = malloc(len)))
		return 0;
	i = 0;
	while (++i <= argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			*str++ = argv[i][j];
			++j;
		}
		*str++ = '\n';
	}
	*(str - 1) = '\0';
	return str - len;
}

int		main(int argc, char **argv)
{
	printf("%s\n", ft_concat_params(argc, argv));
	printf("Debug\n");
	return 0;
}