/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:51:49 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:51:51 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	start = NULL;
	if (!f || !del)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new);
		lst = lst->next;
	}
	return (start);
}
