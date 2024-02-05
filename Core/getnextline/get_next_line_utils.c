/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:37:07 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/05 15:11:58 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_modmemcpy(void *dest, const void *src, size_t len)
{
	size_t	cnt;

	if (!src && !dest)
	{
		return (NULL);
	}
	cnt = 0;
	while (cnt < len)
	{
		*(char *)(dest + cnt) = *(char *)(src + cnt);
		cnt++;
	}
	return (dest);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new_ptr;

	new_ptr = (char *) malloc (sizeof(char) * size);
	if (!new_ptr || !ptr)
		return ((void *)(NULL));
	ft_modmemcpy(new_ptr, ptr, size - 1);
	free(ptr);
	return (new_ptr);
}
