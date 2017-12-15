#include "ft_list.h"
#include <unistd.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

int main()
{
	t_list *list = ft_create_elem("BLABLA");
	ft_list_push_front(&list, "BLIBLI");
	while (list)
	{
		while (*(char*)list->data)
			write(1, (char*)list->data++, 1);
		write(1, "\n", 1);
		list = list->next;
	}
	return 0;
}