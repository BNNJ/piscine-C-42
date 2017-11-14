CC=gcc
CFLAGS=-I.
DEPS = ft_do_op.h ft_opp.h

%.o: %.c $(DEPS)
	$(CC) -Wall -Wextra -Werror -c -o $@ $< $(CFLAGS)

do_op: ft_do_op.o ft_math.o ft_tools.o
	gcc -Wall -Werror -Wextra -o do_op ft_do_op.o ft_math.o ft_tools.o -I.