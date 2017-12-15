#ifndef _FT_LIST_H_
#define	_FT_LIST_H_

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data);

#endif /* _FT_LIST_H_ */