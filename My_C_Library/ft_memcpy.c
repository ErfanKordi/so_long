/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:26:41 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/01 13:02:03 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	c;

	if (!dst && !src)
		return (NULL);
	c = 0;
	d = (char *) dst;
	s = (char *) src;
	while (c < n)
	{
		d[c] = s[c];
		c++;
	}
	return (dst);
}
