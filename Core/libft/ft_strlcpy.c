/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:39:34 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/24 15:01:05 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	if (size > 0)
	{
		while (src[idx] != '\0' && idx < size - 1)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	while (src[idx] != '\0')
		idx++;
	return (idx);
}
