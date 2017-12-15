#include "ft_list.h"
#include <stdio.h>

/* recursive version
t_list	*ft_rev(t_list *rest, t_list *rev)
{
	t_list *current;

	if (!rest)
		return rev;
	current = rest;
	rest = rest->next;
	current->next = rev;
	return ft_rev(rest, current);
}

void	ft_list_reverse(t_list **begin_list)
{
	*begin_list = ft_rev(*begin_list, 0);
}
*/

void	ft_list_reverse(t_list **begin_list)
{
	t_list *current;
	t_list *previous;
	t_list *next;

	previous = 0;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}

/* ########################################################################## */

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
		ft_list_reverse(&list);
		while (list)
		{
			printf("%s\n", (char*)list->data);
			list = list->next;
		}
	}
	return 0;
}