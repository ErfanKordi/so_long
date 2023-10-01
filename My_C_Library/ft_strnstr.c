/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:31:48 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/01 16:39:58 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;
	size_t	i;
	char	*p;

	p = NULL;
	s2_len = ft_strlen((char *)s2);
	i = 0;
	if (s1 == NULL)
	{
		*p = 0;
	}
	if (s2_len == 0)
		return ((char *)s1);
	if (n < s2_len)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(&s1[i], s2, s2_len) == 0)
			return ((char *)&s1[i]);
		if (i + s2_len >= n)
			break ;
		i++;
	}
	return (NULL);
}
