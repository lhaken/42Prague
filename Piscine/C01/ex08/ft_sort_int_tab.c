/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:18:09 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/21 12:29:53 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx_i;
	int	idx_j;
	int	min;

	idx_i = 0;
	while (idx_i < size)
	{
		idx_j = idx_i + 1;
		min = idx_i;
		while (idx_j < size)
		{
			if (tab[idx_j] < tab[min])
			{
				min = idx_j;
			}
			idx_j++;
		}
		ft_swap(&tab[min], &tab[idx_i]);
		idx_i++;
	}
}
