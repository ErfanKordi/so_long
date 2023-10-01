/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %p.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:24:00 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/17 17:50:29 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_address(size_t p, int *len)
{
	char	s[17];
	int		c;
	char	*hx;

	write(1, "0x", 2);
	hx = "0123456789abcdef";
	(*len) += 2;
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
