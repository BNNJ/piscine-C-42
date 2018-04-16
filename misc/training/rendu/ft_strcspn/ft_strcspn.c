/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:57:21 by pfragnou          #+#    #+#             */
/*   Updated: 2018/04/12 13:11:27 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	is_in(const char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		++str;
	}
	return (0);
}

size_t		ft_strcspn(const char *s1, const char *s2)
{
	size_t	n;

	n = 0;
	while (*s1 && !(is_in(*s1, s2)))
	{
		++n;
		++s1;
	}
	return (n);
}

