#include "ft_do_op.h"
#include "ft_opp.h"
#include <unistd.h>

void	ft_usage(void)
{
	int i;

	i = 0;
	write(1, "Error : only [ ", 15);
	while (i < 5)
	{
		ft_putstr(gl_opptab[i].opp);
		write(1, " ", 1);
		++i;
	}
	write(1, "] are accepted.", 15);
}

int	is_opp(char *s1)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(s1, gl_opptab[i].opp))
			return i;
		++i;
	}
	return 5;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return 0;
	else if (is_opp(argv[2]) >= 0)
		gl_opptab[is_opp(argv[2])].fct(ft_atoi(argv[1]), ft_atoi(argv[3]));
	else
		write(1, "0", 1);
	return 0;
}
