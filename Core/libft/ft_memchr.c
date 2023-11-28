/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:44:02 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/24 17:00:43 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	idx;

	if (!s)
	{
		return (NULL);
	}
	idx = 0;
	while (idx < n)
	{
		if (*(unsigned char *)(s + idx) == (unsigned char) c)
		{
			return ((void *) s + idx);
		}
		idx++;
	}
	return (NULL);
}
