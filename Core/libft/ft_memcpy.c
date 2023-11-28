/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:25:46 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/19 18:26:32 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cnt;

	if (!src && !dest)
	{
		return (NULL);
	}
	cnt = 0;
	while (cnt < n)
	{
		*(char *)(dest + cnt) = *(char *)(src + cnt);
		cnt++;
	}
	return (dest);
}
