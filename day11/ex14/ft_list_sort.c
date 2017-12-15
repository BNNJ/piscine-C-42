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
	return *s1 > *s2;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *previous;
	t_list *current;
	t_list *next;

	current = *begin_list;
	while (current->next)
	{
		if (cmp(current->data, current->next->data))
		{
			next = current->next;
			current->next = next->next;
			next->next = current;
			if (current != *begin_list)
				previous->next = next;
			else
				*begin_list = next;
			current = *begin_list;
		}
		else
		{
			previous = current;
			current = current->next;
		}
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

int	 	main(int argc, char **argv)
{
	t_list *list = ft_list_push_params(argc, argv);
	if (argc == 1)
		write(1, "Arguments required\n", 19);
	else
	{
		ft_list_sort(&list, ft_strcmp);
		while (list)
		{
			printf("%s\n", (char*)list->data);
			list = list->next;
		}
	}
	return 0;
}