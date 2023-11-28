/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:53:52 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:54:30 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	idx;

	if (!s || start >= ft_strlen(s))
	{
		res = (char *) malloc (1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	idx = 0;
	if (ft_strlen(&s[start]) <= len)
		len = ft_strlen(&s[start]);
	res = (char *) malloc (len + 1);
	if (!res)
		return (NULL);
	while (s[start + idx] != '\0' && idx < len)
	{
		res[idx] = s[start + idx];
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
