#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *new_elem;

	if (!(new_elem = malloc(sizeof(t_list))))
		return 0;
	new_elem->next = NULL;
	new_elem->data = data;

	return new_elem;
}

int main()
{
	t_list *test = ft_create_elem("BLABLA");
	printf("%s\n", (char*)test->data);
	return 0;
}