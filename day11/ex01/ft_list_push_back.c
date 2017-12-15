#include "ft_list.h"
#include <unistd.h>

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

int main()
{
	t_list *list = ft_create_elem("BLABLA");
	ft_list_push_back(&list, "BLIBLI");
	while (list)
	{
		while (*(char*)list->data)
			write(1, (char*)list->data++, 1);
		write(1, "\n", 1);
		list = list->next;
	}
	return 0;
}


