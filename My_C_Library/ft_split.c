/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:52:11 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/17 17:47:39 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static	size_t	ft_substrcount(char const *s, char c)
{
	int	co;

	co = 0;
	while (*s)
	{
		if (*s != c)
		{
			++co;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (co);
}

static char	**split_return(const char *s, char c, int len, char **r)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			r[i] = ft_substr(s - len, 0, len);
			if (!r[i])
			{
				while (i > 0)
					free(r[--i]);
				free(r);
				return (NULL);
			}
			++i;
		}
		else
			++s;
	}
	return (r);
}

char	**ft_split(const char *s, char c)
{
	char	**r;
	size_t	len;

	len = ft_substrcount(s, c) + 1;
	if (!s)
		return (0);
	r = ft_calloc(len, sizeof(char *));
	if (!r)
		return (NULL);
	return (split_return(s, c, len, r));
}
