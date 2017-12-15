#include "ft_list.h"
#include <stdio.h>

void	ft_swap(void **a, void **b)
{
	void *c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_list_size(t_list *begin_list)
{
	int i;
	
	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++i;
	}
	return i;
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
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

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list *list_ptr;
	unsigned int i;
	unsigned int size;

	i = 0;
	list_ptr = begin_list;
	size = ft_list_size(begin_list);
	while (i <= size / 2)
	{
		ft_swap(&list_ptr->data, &ft_list_at(begin_list, size - i)->data);
		list_ptr = list_ptr->next;
		++i;
	}
}

/* ############################# TEST FUNCTIONS ############################# */

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
		printf("Arguments required\n");
	else
	{
		ft_list_reverse_fun(list);
		while (list)
		{
			printf("%s\n", (char*)list->data);
			list = list->next;
		}
	}
	return 0;
}