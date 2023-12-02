/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:58:51 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/19 09:06:52 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	dest_len;

	idx = 0;
	dest_len = ft_strlen(dest);
	while (src[idx] != '\0')
	{
		dest[dest_len + idx] = src[idx];
		idx++;
	}
	dest[dest_len + idx] = '\0';
	return (dest);
}

int	ft_getsize(int size, char **strs, char *sep)
{
	int	len;
	int	sep_len;
	int	idx;

	len = 0;
	idx = 0;
	if (size != 0)
	{
		while (idx < size)
		{
			len = len + ft_strlen(strs[idx]);
			idx++;
		}
		sep_len = (size - 1) * ft_strlen(sep);
		return (len + sep_len + 1);
	}
	else
	{
		return (1);
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		idx;

	idx = 0;
	res = (char *) malloc(ft_getsize(size, strs, sep));
	res[0] = '\0';
	while (idx < size)
	{
		res = ft_strcat(res, strs[idx]);
		if (idx < size - 1)
		{
			res = ft_strcat(res, sep);
		}
		idx++;
	}
	res[ft_getsize(size, strs, sep) - 1] = '\0';
	return (res);
}
