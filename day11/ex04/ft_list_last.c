#include "ft_list.h"
#include <stdio.h>

t_list *ft_list_last(t_list *begin_list)
{
	t_list *tmp;

	tmp = begin_list;
	while (tmp->next)
		tmp = tmp->next;
	return tmp;
}

int	main()
{
	t_list *test1 = ft_create_elem("1");
	t_list *test2 = ft_create_elem("2");
	t_list *test3 = ft_create_elem("3");
	t_list *test4 = ft_create_elem("4");
	
	test1->next = test2;
	test2->next = test3;
	test3->next = test4;

	printf("%s\n", (char*)(ft_list_last(test1))->data);
	return 0;
}
