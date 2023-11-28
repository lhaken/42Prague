/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:44:08 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/24 15:48:22 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if ((unsigned char) c == '\0')
	{
		return ((char *)(s + len));
	}
	while (len >= 0)
	{
		if (s[len] == (unsigned char) c)
		{
			return ((char *)(s + len));
		}
		len--;
	}
	return (NULL);
}
