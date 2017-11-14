#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return *s1 - *s2;
}

void	ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			write(1, tab[i] + j, 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

void	ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
	unsigned int i;
	char *temp = 0;

	i = 0;
	while (tab[i + 1] != 0)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			++i;
	}
}

int	main()
{
	char *tab[] = {"Hello", "Darkness", "My", "Old", "Friend", 0};

	ft_print_words_tables(tab);
	ft_advanced_sort_wordtab(tab, ft_strcmp);
	ft_print_words_tables(tab);
	return 0;
}
