/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:57:11 by lhaken            #+#    #+#             */
/*   Updated: 2023/11/18 13:05:29 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	plc;

	plc = 0;
	if (n < 0)
	{
		plc++;
	}
	if (n == 0)
	{
		plc ++;
	}
	while (n != 0)
	{
		n = n / 10;
		plc++;
	}
	return (plc);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		idx;
	int		minus;

	idx = ft_numlen(n);
	minus = 1;
	res = (char *) malloc (idx + 1);
	if (!res)
		return (NULL);
	res[idx] = '\0';
	idx--;
	if (n < 0)
	{
		res[0] = '-';
		minus = -1;
	}
	if (n == 0)
		res[idx] = '0';
	while (n != 0)
	{
		res[idx] = minus * (n % 10) + '0';
		n = n / 10;
		idx--;
	}
	return (res);
}
