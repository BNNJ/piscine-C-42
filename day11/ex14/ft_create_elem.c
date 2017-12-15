#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *new_elem;

	if (!(new_elem = malloc(sizeof(t_list))))
		return 0;
	new_elem->next = NULL;
	new_elem->data = data;

	return new_elem;
}