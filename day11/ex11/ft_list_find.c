#include "ft_list.h"
#include <stdio.h>
#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return *s1 - *s2 == 0 ? 1 : 0;
}

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if (cmp(list_ptr->data, data_ref))
			return list_ptr;
		list_ptr = list_ptr->next;
	}
	return ft_create_elem("No match found");
}


void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *tmp;

	tmp = *begin_list;
	if (*begin_list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *list_ptr;
	int i;

	i = 0;
	list_ptr = 0;
	while (++i < ac)
		ft_list_push_back(&list_ptr, av[i]);
	return list_ptr;
}

int	 	main(int argc, char **argv)
{
	t_list *list = ft_list_push_params(argc, argv);
	if (argc == 1)
		write(1, "Arguments required\n", 19);
	else
		printf("%s\n", (char*)ft_list_find(list, "Frind", ft_strcmp)->data);
	return 0;
}