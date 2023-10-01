/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %u.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:13:00 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/15 14:31:26 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsignedint(unsigned int c, int *len)
{
	if (c >= 10)
		ft_unsignedint(c / 10, len);
	ft_putchar(c % 10 + '0', len);
}
