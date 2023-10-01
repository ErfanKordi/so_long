/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:34:51 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/17 19:54:15 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_putnum(unsigned int p, int *len, char x_or_x)
{
	char	s[20];
	int		c;
	char	*hx;

	if (x_or_x == 'X')
		hx = "0123456789ABCDEF";
	else
		hx = "0123456789abcdef";
	c = 0;
	if (p == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (p != 0)
	{
		s[c] = hx[p % 16];
		p = p / 16;
		c++;
	}
	while (c--)
		ft_putchar(s[c], len);
}
