#ifndef	_FT_BTREE_H_
#define	_FT_BTREE_H_

#include <stdlib.h>

typedef struct	s_btree
{
	struct s_btree	*left:
	struct s_btree	*right;
	void			*item;
}				t_btree;

t_btree	btree_create_node(void *item);

#endif	/* _FT_BTREE_H_ */