#include "ft_list.h"
#include <stdio.h>

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 1;
	while (begin_list && i <= nbr)
	{
		if (i == nbr)
			return begin_list;
		begin_list = begin_list->next;
		++i;
	}
	return 0;
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

int	 main(int argc, char **argv)
{
	t_list *list = ft_list_push_params(argc, argv);
	if (argc == 1)
		printf("Arguments required\n");
	else
	{
		printf("%s\n", (char*)ft_list_at(list, 3)->data);
	}
	return 0;
}