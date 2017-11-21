CC = gcc
CFLAGS = -Wall -Wextra -Werror -iquote includes
SDIR = srcs/
SRCS = ft_putchar.c	\
	ft_putstr.c	\
	ft_strlen.c	\
	ft_strcmp.c	\
	ft_swap.c
OBJS = $(SRCS:.c=.o)
INCL = includes/libft.h

NAME = libft.a
RM = del

.PHONY :	all clean fclean re mclean

all : 		$(NAME)

$(NAME):	$(OBJS)
	ar rc $@ $?
	ranlib $@

%.o :		$(SDIR)%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :		fclean all

mclean :	all clean
