CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_do_op.c ft_math.c ft_tools.c
OBJS = $(SRCS:.c=.o)
DEPS = ft_do_op.h ft_opp.h
BIN = do_op
EXT = .exe

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS) $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY : clean fclean re
clean :
	del $(OBJS)

fclean : clean
	del $(BIN)$(EXT)

re : fclean $(BIN)