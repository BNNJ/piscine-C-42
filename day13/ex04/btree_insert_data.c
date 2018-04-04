#include "../ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void*, void*))
{
	t_btree	*new;

	new = btree_create_node(item);
	if (!(*root))
		(*root) = new;
	else if (cmpf(new->item, (*root)->item) < 0)
		(*root)->left = new;
	else
		(*root)->right = new;
}