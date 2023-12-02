/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:33:57 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/26 13:30:44 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int lenght, int (*f)(int, int))
{
	int	idx;

	idx = 0;
	while (idx < lenght - 1)
	{
		if (f(tab[idx], tab[idx + 1]) > 0)
		{
			return (0);
		}
		idx++;
	}
	return (1);
}
