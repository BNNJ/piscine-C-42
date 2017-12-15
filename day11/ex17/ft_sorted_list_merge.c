#include "ft_list.h"
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return *s1 > *s2;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *list_ptr;
	t_list *tmp;

	list_ptr = *begin_list;
	if (!cmp(data, list_ptr->data))
	{
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = list_ptr;
	}
	else
	{
		while (list_ptr && cmp(data, list_ptr->data))
		{
			tmp = list_ptr;
			list_ptr = list_ptr->next;
		}
		tmp->next = ft_create_elem(data);
		tmp->next->next = list_ptr;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, 
							t_list *begin_list2, 
							int (*cmp)())
{
	while (begin_list2)
	{
		ft_sorted_list_insert(begin_list1, begin_list2->data, cmp);
		begin_list2 = begin_list2->next;
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
	t_list *list2 = ft_create_elem("B");
	t_list *tmp = list2;
	
	list2->next = ft_create_elem("D");
	list2 = list2->next;
	list2->next = ft_create_elem("F");
	list2 = tmp;

	if (argc == 1)
		printf("Arguments required\n");
	else
	{
		ft_sorted_list_merge(&list, list2, ft_strcmp);
		while (list)
		{
			printf("%s\n", (char*)list->data);
			list = list->next;
		}
		printf("-\n");
		while (list2)
		{
			printf("%s\n", (char*)list2->data);
			list2 = list2->next;
		}
	}
	return 0;
}