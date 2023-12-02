/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:49:35 by lhaken            #+#    #+#             */
/*   Updated: 2023/09/14 11:14:40 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power <= 0)
	{
		if (power == 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	else if (power != 0)
	{
		return (ft_recursive_power(nb, power - 1) * nb);
	}
	else
	{
		return (0);
	}
}
