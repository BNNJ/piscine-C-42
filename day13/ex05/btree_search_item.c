#include "../ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void*))
{
	if (!root)
		return 0;
	btree_search_item(left, data_ref, &cmpf);
	if (cmpf(root->item, data_ref) == 0)
		return root->item;
	btree_search_item(right, data_ref, &cmpf);
}