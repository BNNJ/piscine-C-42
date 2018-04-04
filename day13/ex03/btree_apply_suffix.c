#include "../ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	btree_apply_suffix(left, &applyf);
	btree_apply_suffix(right, &applyf);
	applyf(root->item);
}