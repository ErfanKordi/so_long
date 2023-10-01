/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:57:25 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/11 14:57:16 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*holder;
	void	*content;

	new = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		holder = ft_lstnew(content);
		if (!holder)
		{
			(*del)(content);
			ft_lstclear(&new, del);
			free(new);
			return (NULL);
		}
		ft_lstadd_back(&new, holder);
		lst = lst->next;
	}
	return (new);
}
