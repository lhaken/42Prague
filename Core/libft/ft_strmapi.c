/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:51:56 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:51:59 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*res;

	idx = 0;
	res = (char *) malloc (ft_strlen(s) + 1);
	if (!res)
	{
		return (NULL);
	}
	while (s[idx] != '\0')
	{
		res[idx] = f(idx, s[idx]);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
