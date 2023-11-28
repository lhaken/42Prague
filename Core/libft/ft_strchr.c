/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:32:08 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:55:14 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == (unsigned char) c)
		{
			return ((char *)(s + idx));
		}
		idx++;
	}
	if ((unsigned char) c == '\0')
	{
		return ((char *)(s + idx));
	}
	return (NULL);
}
