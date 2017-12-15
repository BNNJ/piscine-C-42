#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return *s1 - *s2 != 0;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;
	t_list *tmp;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	list_ptr = *begin_list;
	while (list_ptr && list_ptr->next)
	{
		if (!cmp(list_ptr->next->data, data_ref))
		{
			tmp = list_ptr->next;
			list_ptr->next = tmp->next;
			free(tmp);
		}
		else
			list_ptr = list_ptr->next;
	}
}

/*
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	if (*begin_list)
	{
		if (!cmp((*begin_list)->data, data_ref))
		{
			tmp = *begin_list;
			*begin_list = (*begin_list)->next;
			free(tmp);
			ft_list_remove_if(begin_list, data_ref, cmp);
		}
		else
			ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
	}
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
	{
		ft_list_remove_if(&list, "X", ft_strcmp);
		while (list)
		{
			while (*(char*)list->data)
				write(1, (char*)list->data++, 1);
			write(1, "\n", 1);
			list = list->next;
		}
	}
	return 0;
}