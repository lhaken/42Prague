/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:19:47 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/26 11:28:56 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int lenght, int (*f)(char*))
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (idx < lenght)
	{
		if (f(tab[idx]) != 0)
		{
			count++;
		}
		idx++;
	}
	return (count);
}
