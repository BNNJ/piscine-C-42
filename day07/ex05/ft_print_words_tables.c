#include <unistd.h>

char	**ft_split_whitespaces(char *str);

void	ft_print_words_tables(char **tab)
{
	while (*tab)
	{
		while (**tab)
			write(1, (*tab)++, 1);
		write(1, "\n", 1);
		++tab;
	}
}

int		main()
{
	char *str = "Hello Darkness My Old Friend";

	ft_print_words_tables(ft_split_whitespaces(str));
	return 0;
}