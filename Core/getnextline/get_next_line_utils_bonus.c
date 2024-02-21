/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:37:07 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/05 15:11:58 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	if (!s)
		return (NULL);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	cnt;

	cnt = 0;
	if (size != 0 && SIZE_MAX / size < nmemb)
	{
		return (NULL);
	}
	res = (void *) malloc (nmemb * size);
	if (!res)
	{
		return ((void *)(NULL));
	}
	while (cnt < nmemb * size)
	{
		*(char *)(res + cnt) = (char) 0;
		cnt++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
