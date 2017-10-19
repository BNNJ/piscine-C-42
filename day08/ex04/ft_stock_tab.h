#ifndef _FT_STOCK_TAB_H_
#define _FT_STOCK_TAB_H_
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_stock_par
{
	int size_param;
	char *str;
	char *copy;
	char **tab;
}				t_stock_par;
#endif