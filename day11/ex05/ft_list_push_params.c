#include "ft_list.h"
#include <stdio.h>

/*
t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *new_elem;
	t_list *tmp;
	int i;

	i = 1;
	new_elem = (ac == 1) ? 0 : ft_create_elem(av[i]);
	while (++i < ac)
	{
		tmp = new_elem;
		new_elem = ft_create_elem(av[i]);
		new_elem->next = tmp;
	}
	return new_elem;
}
*/

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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *list_ptr;
	int i;

	i = 0;
	list_ptr = 0;
	while (++i < ac)
		ft_list_push_front(&list_ptr, av[i]);
	return list_ptr;
}

int	 main(int argc, char **argv)
{
	t_list *new_list = ft_list_push_params(argc, argv);
	if (argc == 1)
		printf("Arguments required\n");
	else
	{
		while (new_list)
		{
			printf("%s\n", (char*)new_list->data);
			new_list = new_list->next;
		}
	}
	return 0;
}