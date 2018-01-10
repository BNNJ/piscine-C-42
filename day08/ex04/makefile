CC = gcc
CFLAGS = -Wall -Wextra -Werror -iquote includes
SDIR = srcs/
SRCS = ft_param_to_tab.c \
		ft_show_tab.c \
		ft_split_whitespaces.c \

OBJS = $(SRCS:.c=.o)
INCL = ft_stock_par.h

ifeq ($(OS), Windows_NT)
	NAME = advanced_op-op.exe
	RM = del
else
	NAME = ft_test
	RM = rm -f
endif

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