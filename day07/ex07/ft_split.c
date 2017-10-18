#include <stdlib.h>
#include <stdio.h>

int		is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset || c == '\0')
			return 1;
		++charset;
	}
	return 0;
}

int		word_count(char *str, char *charset)
{
	unsigned int words;

	words = 0;
	while (*str)
	{
		if (!is_separator(*str, charset) && is_separator(*(str + 1), charset))
			++words;
		++str;
	}
	return words;
}

char	**ft_split(char *str, char *charset)
{
	char **tab;
	unsigned int len;
	unsigned int i;
	unsigned int k;

	i = 0;
	if (!(tab = malloc(sizeof(char*) * word_count(str, charset) + 1)))
		return 0;
	while (*str)
	{
		while (is_separator(*str, charset) && *str)
			++str;
		len = 0;
		while (!is_separator(str[len], charset))
			++len;
		if (!(tab[i] = malloc(len + 1)))
			return 0;
		k = 0;
		while (!is_separator(*str, charset))
			tab[i][k++] = *str++;
		tab[i][k] = '\0';
		++i;
	}
	tab[i] = 0;
	return tab;
}

int		main(int argc, char **argv)
{
	char *str = (argc > 1) ? argv[1] : "Hello Darkness My Old Friend";
	char *charset = (argc > 2) ? argv[2] : " \n\t\f\r\v";
	char **tab = ft_split(str, charset);
	int i = 0;

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		++i;
	}
	return 0;
}