#include "../ft_btree.h"

int	btree_level_count(t_btree *root)
{
	if (!root)
		return 0;
	return (1 + btree_level_count(left) > 1 + btree_level_count(right))
		? 1 + btree_level_count(left) : 1 + btree_level_count(right);
}