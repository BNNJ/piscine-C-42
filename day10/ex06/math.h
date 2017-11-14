#ifndef _MATH_H_
# define _MATH_H_
# include <unistd.h>
# include <stdlib.h>
# define CHECK_ARG(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')

void	ft_putnbr(const int nb);
void	ft_add(const int a, const int b);
void	ft_sub(const int a, const int b);
void	ft_div(const int a, const int b);
void	ft_mult(const int a, const int b);
void	ft_mod(const int a, const int b);

#endif /* _MATH_H_ */