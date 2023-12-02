/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:48:52 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/19 08:47:53 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*arr;
	int	index;

	len = max - min;
	index = 0;
	if (min < max)
	{
		arr = (int *) malloc(sizeof(int) * len);
		while (min < max)
		{
			arr[index] = min;
			index++;
			min++;
		}
		return (arr);
	}
	else
	{
		return (0);
	}
}
