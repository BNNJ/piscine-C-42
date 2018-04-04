#include "../ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	applyf(root->item);
	btree_apply_prefix(left, &applyf);
	btree_apply_prefix(right, &applyf);
}