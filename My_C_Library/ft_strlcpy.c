/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:53:15 by ekordi            #+#    #+#             */
/*   Updated: 2023/03/21 13:53:15 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[c] != '\0' && c < n -1)
	{
		dst[c] = src[c];
		c++;
	}
	if (n > 0)
		dst[c] = '\0';
	while (src[c] != '\0')
		c++;
	return (c);
}
