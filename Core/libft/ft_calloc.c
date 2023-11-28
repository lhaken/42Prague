/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:53:00 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:53:37 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size != 0 && SIZE_MAX / size < nmemb)
	{
		return (NULL);
	}
	res = (void *) malloc (nmemb * size);
	if (!res)
	{
		return ((void *)(NULL));
	}
	ft_bzero(res, nmemb * size);
	return (res);
}
