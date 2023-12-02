/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:21:03 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/20 12:59:06 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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

char	*ft_wrdstrncpy(char *src, unsigned int n)
{
	char			*dest;	
	unsigned int	idx;

	dest = (char *) malloc(n + 1);
	idx = 0;
	while (src[idx] != 0)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			count;
	char		*word;
	t_stock_str	*ar;

	count = 0;
	ar = (struct s_stock_str *) malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!ar)
	{
		return (NULL);
	}
	while (count < ac)
	{
		word = av[count];
		ar[count].size = ft_strlen(word);
		ar[count].str = word;
		ar[count].copy = ft_wrdstrncpy(word, ar[count].size);
		count++;
	}
	ar[count].str = 0;
	return (ar);
}
