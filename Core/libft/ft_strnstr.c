/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:18:29 by lhaken            #+#    #+#             */
/*   Updated: 2023/10/26 23:46:56 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	curr;
	size_t	shift;

	if (!(*little))
		return ((char *) big);
	curr = 0;
	while (big[curr] != '\0' && curr < len)
	{
		shift = 0;
		while (big[curr + shift] == little[shift] && curr + shift < len)
		{
			shift++;
			if (little[shift] == '\0')
				return ((char *)(&big[curr]));
		}
		curr++;
	}
	return (0);
}
