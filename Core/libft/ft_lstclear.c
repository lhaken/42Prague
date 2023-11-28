/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:52:40 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:52:41 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !*lst || !del)
	{
		return ;
	}
	while (lst != NULL && *lst != NULL)
	{
		current = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = current;
	}
}
