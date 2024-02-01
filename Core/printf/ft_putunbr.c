/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:39:02 by lhaken            #+#    #+#             */
/*   Updated: 2024/02/01 21:39:03 by lhaken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, size_t *cnt)
{
	unsigned int	rem;

	(*cnt)++;
	if (n > 9)
	{
		rem = (n % 10) + '0';
		n = n / 10;
		ft_putunbr(n, cnt);
		write(1, &rem, 1);
	}
	else
	{
		n = n + '0';
		write(1, &n, 1);
	}
}
