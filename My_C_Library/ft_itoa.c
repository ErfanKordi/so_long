/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:08:45 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/01 13:08:45 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_numlen(int n)
{
	int	c;

	c = 1;
	if (n < 0)
	{
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static char	*num(int n, char *r, int clen, int isneg)
{
	int		e;

	e = ft_numlen(n);
	while (clen--)
	{
		r[clen + isneg] = (n % 10) + 48;
		n /= 10;
	}
	if (isneg)
		r[0] = '-';
	r [e + isneg] = '\0';
	return (r);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		clen;
	int		isneg;

	isneg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	clen = ft_numlen(n);
	if (n < 0)
	{
		isneg = 1;
		n = -n;
	}
	r = (char *)malloc(sizeof(char) * (clen + isneg + 1));
	if (!r)
		return (NULL);
	num(n, r, clen, isneg);
	return (r);
}
