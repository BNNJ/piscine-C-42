#ifndef _FT_OPP_H_
# define _FT_OPP_H_

t_opp gl_opptab[] = {
	{"-", &ft_sub}, \
	{"+", &ft_add}, \
	{"*", &ft_mul}, \
	{"/", &ft_div}, \
	{"%", &ft_mod}, \
	{"", &ft_usage}};

#endif /* _FT_OPP_H_ */