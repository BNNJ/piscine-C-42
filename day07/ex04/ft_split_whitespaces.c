#include <stdlib.h>
#include <stdio.h>
#define IS_WHITESPACE(x) (((x) >= 9 && (x) <= 13) || (x) == 32 || (x) == 0) 

int		word_count(char *str)
{
	unsigned int words;

	words = 0;
	while (*str)
	{
		if (!IS_WHITESPACE(*str) && IS_WHITESPACE(*(str + 1)))
			++words;
		++str;
	}
	return words;
}

char	**ft_split_whitespaces(char *str)
{
	char **tab;
	unsigned int len;
	unsigned int i;
	unsigned int k;

	i = 0;
	if (!(tab = malloc(sizeof(char*) * word_count(str) + 1)))
		return 0;
	while (*str)
	{
		while (IS_WHITESPACE(*str) && *str)
			++str;
		len = 0;
		while (!IS_WHITESPACE(str[len]))
			++len;
		if (!(tab[i] = malloc(len + 1)))
			return 0;
		k = 0;
		while (!IS_WHITESPACE(*str))
			tab[i][k++] = *str++;
		tab[i][k] = '\0';
		++i;
	}
	tab[i] = 0;
	return tab;
}

int		main()
{
	char *str = "Hello   Darkness         My  Old    Friend";
	char **tab = ft_split_whitespaces(str);
	int i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		++i;
	}
	return 0;
}