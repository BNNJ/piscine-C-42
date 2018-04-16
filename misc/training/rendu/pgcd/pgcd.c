/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:13:12 by pfragnou          #+#    #+#             */
/*   Updated: 2018/04/12 13:22:42 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		pgcd(int a, int b)
{
	
	while (a - b != 0)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return (a);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		printf("%i\n", pgcd(atoi(argv[1]), atoi(argv[2])));
	else
		printf("\n");
	return (0);
}
