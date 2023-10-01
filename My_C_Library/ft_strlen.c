/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/03/15 09:25:39 by ekordi            #+#    #+#             */
/*   Updated: 2023/03/15 09:25:39 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}
