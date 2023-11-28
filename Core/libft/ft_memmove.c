/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:26:45 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/19 18:30:37 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	cnt;

	if (!src && !dest)
	{
		return (NULL);
	}
	if (src < dest)
	{
		cnt = n - 1;
		while (cnt + 1 > 0)
		{
			*(char *)(dest + cnt) = *(char *)(src + cnt);
			cnt--;
		}
	}
	else
	{
		cnt = 0;
		while (cnt < n)
		{
			*(char *)(dest + cnt) = *(char *)(src + cnt);
			cnt++;
		}
	}
	return (dest);
}
