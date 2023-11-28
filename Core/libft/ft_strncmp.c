/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:49:31 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/24 16:40:55 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (s1[idx] != '\0' && idx < n)
	{
		if ((unsigned char) s1[idx] > (unsigned char) s2[idx])
			return ((unsigned char) s1[idx] - (unsigned char) s2[idx]);
		else if ((unsigned char) s1[idx] < (unsigned char) s2[idx])
			return ((unsigned char) s1[idx] - (unsigned char) s2[idx]);
		idx++;
	}
	if (s1[idx] == '\0' && s2[idx] != '\0' && n >= 1)
		return ((unsigned char) s1[idx] - (unsigned char) s2[idx]);
	return (0);
}
