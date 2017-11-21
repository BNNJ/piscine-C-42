CC = gcc
CFLAGS = -Wall -Wextra -Werror -iquote includes
SDIR = srcs/
SRCS = ft_do_op.c \
	ft_math.c \
	ft_tools.c \

OBJS = $(SRCS:.c=.o)
INCL = includes/ft_do_op.h includes/ft_opp.h

NAME = ft_advanced_do-op.exe
RM = del

.PHONY :	all clean fclean re mclean

all : 		$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $@ $? $(CFLAGS)

%.o :		$(SDIR)%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :		fclean all

mclean :	all clean
