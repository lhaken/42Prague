/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:02:20 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/24 17:15:19 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (*(unsigned char *)(s1 + idx) != *(unsigned char *)(s2 + idx))
			return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
		idx++;
	}
	if (*(unsigned char *)(s1 + idx) == '\0'
		&& *(unsigned char *)(s2 + idx) != '\0'
		&& n >= 1)
	{
		return (*(unsigned char *)(s1 + idx) - *(unsigned char *)(s2 + idx));
	}
	return (0);
}
