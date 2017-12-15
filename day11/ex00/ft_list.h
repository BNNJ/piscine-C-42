#ifndef _FT_LIST_H_
#define	_FT_LIST_H_

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif /* _FT_LIST_H_ */