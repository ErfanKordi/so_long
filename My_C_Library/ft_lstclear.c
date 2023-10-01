/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:17:52 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/11 13:53:55 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*holder;

	if (!lst)
		return ;
	while (*lst)
	{
		holder = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = holder;
	}
}
