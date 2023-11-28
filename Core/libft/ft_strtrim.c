/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:56:50 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 12:56:56 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_getstart(char const *s1, char const *set)
{
	int	idx;

	idx = 0;
	while (ft_inset(s1[idx], set) == 1 && s1[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

static int	ft_getend(char const *s1, char const *set)
{
	int	idx;

	idx = ft_strlen(s1) - 1;
	while (ft_inset(s1[idx], set) == 1)
	{
		idx--;
	}
	return (idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		s_idx;
	int		e_idx;
	int		idx;

	s_idx = ft_getstart(s1, set);
	e_idx = ft_getend(s1, set);
	if (s_idx > e_idx)
	{
		res = (char *) malloc (1);
		res[0] = '\0';
		return (res);
	}
	res = (char *) malloc (e_idx - s_idx + 2);
	idx = 0;
	while (s_idx <= e_idx)
	{
		res[idx] = s1[s_idx];
		s_idx++;
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
