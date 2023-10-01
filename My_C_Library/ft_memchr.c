/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:22:34 by ekordi            #+#    #+#             */
/*   Updated: 2023/03/30 16:56:57 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char		*r;
	const unsigned char		*s;

	s = (const unsigned char *)src;
	r = NULL;
	while (n > 0)
	{
		if (*s == (unsigned char)c)
		{
			r = s;
			break ;
		}
		s++;
		n--;
	}
	return ((void *)r);
}
