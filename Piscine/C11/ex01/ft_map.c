/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:23:33 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/26 10:41:42 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int	*ar;
	int	idx;

	ar = (int *) malloc(sizeof(int) * (lenght));
	idx = 0;
	while (idx < lenght)
	{
		ar[idx] = f(tab[idx]);
		idx++;
	}
	return (ar);
}
