/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:34:59 by ekordi            #+#    #+#             */
/*   Updated: 2023/03/29 17:32:38 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sd;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	sd = (char *)malloc((len + 1) * sizeof(char));
	if (sd == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		sd[i] = s[i];
		i++;
	}
	sd[i] = '\0';
	return (sd);
}
