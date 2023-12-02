/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:15:40 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/18 14:28:49 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	index;

	len = max - min;
	*range = (int *) malloc(sizeof(int) * len);
	index = 0;
	if (min < max)
	{
		while (min < max)
		{
			(*range)[index] = min;
			index++;
			min++;
		}
		return (len);
	}
	else
	{
		*range = (void *) 0;
		return (0);
	}
}
