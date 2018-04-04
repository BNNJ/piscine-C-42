#include "../ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	btree_apply_infix(left, &applyf);
	applyf(root->item);
	btree_apply_infix(right, &applyf);
}