#include "ft_list.h"
#include <stdio.h>
#include <unistd.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *tmp;

	tmp = *begin_list1;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = begin_list2;
}

int		main()
{
	t_list *list1;
	t_list *list2;
	t_list *tmp;
	t_list **list_ptr;
	int i = 0;
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	tmp = 0;
	while (i < 5)
	{
		list1 = ft_create_elem(tab + i);
		list1->next = tmp;
		tmp = list1;
		++i;
	}
	list_ptr = &list1;
	tmp = 0;
	while (i < 10)
	{
		list2 = ft_create_elem(tab + i);
		list2->next = tmp;
		tmp = list2;
		++i;
	}
	ft_list_merge(list_ptr, list2);
	while (list1)
	{
		printf("%d\n", *(int*)(list1->data));
		list1 = list1->next;
	}
	return 0;
}