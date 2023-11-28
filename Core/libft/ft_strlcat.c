/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:42:24 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/26 23:57:05 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	idx;

	dst_len = ft_strlen(dst);
	idx = 0;
	if (dst_len < size - 1 && size > 0)
	{
		while (src[idx] != '\0' && dst_len + idx < size - 1)
		{
			dst[dst_len + idx] = src[idx];
			idx++;
		}
		dst[dst_len + idx] = '\0';
	}
	if (size <= dst_len)
		dst_len = size;
	return (dst_len + ft_strlen(src));
}
