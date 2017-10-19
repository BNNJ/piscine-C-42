#include "ft_stock_tab.h"
char	**ft_split_whitespaces(char *str);
void	ft_show_tab(t_stock_par *par);

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

t_stock_par *ft_param_to_tab(int ac, char **av)
{
	t_stock_par *struct_tab;
	int i;
	unsigned int arg_len;

	if (!(struct_tab = (t_stock_par*)malloc(sizeof(t_stock_par) * ac + 1)))
		return 0;
	i = 0;
	while (i < ac)
	{
		arg_len = 0;
		while (av[i][arg_len])
			++arg_len;
		struct_tab[i].size_param = arg_len;
		struct_tab[i].str = av[i];
		struct_tab[i].copy = ft_strdup(av[i]);
		struct_tab[i].tab = ft_split_whitespaces(av[i]);
		++i;
	}
	struct_tab[i].str = '\0';
	return struct_tab;
}

int	main(int argc, char **argv)
{
	ft_show_tab(ft_param_to_tab(argc, argv));
	return 0;
}