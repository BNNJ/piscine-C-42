ifeq ($(OS), Windows_NT)
	D_OS = Win
else
	D_OS = Other
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror -iquote includes
SDIR = srcs/
SRCS = ft_do_op.c \
	ft_math.c \
	ft_tools.c \

OBJS = $(SRCS:.c=.o)
INCL = includes/ft_do_op.h includes/ft_opp.h

ifeq ($(D_OS),Win)
	NAME = advanced_op-op.exe
	RM = del
else
	NAME = advanced_op-op.out
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
