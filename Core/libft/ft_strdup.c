/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:54:42 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:54:43 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*d;

	if (!s)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	d = (char *) malloc (len + 1);
	if (!d)
	{
		return (NULL);
	}
	ft_strlcpy(d, s, len + 1);
	return (d);
}
