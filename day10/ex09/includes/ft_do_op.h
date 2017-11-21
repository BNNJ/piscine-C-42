#ifndef _FT_DO_OP_H_
# define _FT_DO_OP_H_

int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_usage();
void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_div(int a, int b);
void	ft_mul(int a, int b);
void	ft_mod(int a, int b);

typedef struct	s_opp
{
	char *opp;
	void (*fct)(int, int);
}				t_opp;

#endif /* _FT_DO_OP_H_ */