#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;

	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
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
	t_list *new_list = ft_list_push_params(argc, argv);
	t_list *list = new_list;

	if (argc == 1)
		printf("Arguments required\n");
	else
	{
		while (list->next)
		{
			printf("%s\n", (char*)list->data);
			list = list->next;
		}
		ft_list_clear(&new_list);
		list = new_list;
		if (list)
			printf("%s\n", (char*)list->data);
		else
			printf("Que dalle\n");
	}
	return 0;
}